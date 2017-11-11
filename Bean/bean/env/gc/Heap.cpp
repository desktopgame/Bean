#include "Heap.h"
#include "Block.h"
#include "GCStrategy.h"
#include "HeapMutexLock.h"
#include "IncrementalGCStrategy.h"
#include "MarkAndSweepGCStrategy.h"
#include "../Class.h"
#include "../ClassLoader.h"
#include "../CodeBlock.h"
#include "../Field.h"
#include "../Object_.h"
#include "../Package.h"
#include "../user/UserSystem.h"
#include "../../util/Memory.h"
#include "../../threads/Thread.h"
#include "../../util/TimeSpan.h"

//public method---
void Heap::add(Object_ * obj) {
	std::lock_guard<std::recursive_mutex> lock(thread_sync);
	this->objects.emplace_back(obj);
	strategy->handleNew(obj);
	int x = this->locks;
	test();
}

void Heap::remove(Object_ * obj) {
	std::lock_guard<std::recursive_mutex> lock(thread_sync);
	for (int i = 0; i < objects.size(); i++) {
		Object_*  elem = objects.at(i);
		if (obj == elem) {
			objects.erase(objects.begin() + i);
			break;
		}
	}
}

void Heap::view(std::function<void(std::vector<Object_*>&)> f) {
	std::lock_guard<std::recursive_mutex> lock(thread_sync);
	std::vector<Object_*> o = this->objects;
	f(o);
	this->objects = o;
}

void Heap::writeBarrier(Object_ * left, Object_ * right) {
	if (left == nullptr || right == nullptr) {
		return;
	}
	auto leftState = left->getState();
	auto rightState = right->getState();
	if (leftState->getProgress() == GCProgress::Pending) {
		leftState->setProgress(GCProgress::SearchNow);
		strategy->handleWriteBarrier(left);
	}
	if (leftState->getProgress() == GCProgress::SearchComp &&
		(rightState->getProgress() == GCProgress::NotSearch ||
		 rightState->getProgress() == GCProgress::Pending)) {
		rightState->setProgress(GCProgress::SearchNow);
		this->strategy->handleWriteBarrier(right);
	}
}

void Heap::writeBarrier(Object_ * right) {
	if (right == nullptr ||
		right->getState() == nullptr) {
		return;
	}
//	if (right->getState()->getProgress() == GCProgress::NotSearch) {
//		right->getState()->setProgress(GCProgress::SearchNow);
		this->strategy->handleWriteBarrier(right);
//	}
}

bool Heap::deleteItem(Object_ * obj) {
	if (obj->getState()->isMarked()) {
		return false;
	}
	CodeBlock::sweep_item(obj);
	Block::blocks_page_remove(obj);
	return true;
}

void Heap::miniGC() {
	std::lock_guard<std::recursive_mutex> lock(thread_sync);
	if (!Thread::getCurrentOrSystem()->isSystemThread()) {
		return;
	}
	execImpl(0);
}

void Heap::fullGC() {
	std::lock_guard<std::recursive_mutex> lock(thread_sync);
	if (!Thread::getCurrentOrSystem()->isSystemThread()) {
		return;
	}
	execImpl(1);
}

void Heap::lock() {
	locks++;
}

void Heap::unlock() {
	locks--;
	//Heap::getInstance()->test();
}

void Heap::test() {
	if (locked()) {
		return;
	}
	//現在のオブジェクト数が閾値を超えている
	if (objects.size() >= getHeapThreshold()) {
		int old = objects.size();
		Heap::miniGC();
		//objects.shrink_to_fit();
		//参考URL:http://kmaebashi.com/programmer/devlang/array.html
		//現在のオブジェクト数に閾値を加算
		if (old != objects.size()) {
			this->heapThreshold = objects.size() + getHeapThreshold();
		}
	}
}

void Heap::dump() {
	std::cout << "--- DUMP GC Object_ ---" << std::endl;
	for (Object_* obj : objects) {
		Object_* val = obj;
		std::cout << "    Addre: " << Memory::getAddres(obj);
		if (val != nullptr) {
			std::cout << " ";
			val->dump();
		} else {
			std::cout << std::endl;
		}
	}
}

int Heap::getHeapThreshold() {
	if (this->gcAlways) {
		return 0;
	}
	return this->heapThreshold;
}

int Heap::getCurrentSize() {
	std::lock_guard<std::recursive_mutex> lock(thread_sync);
	return objects.size();
}

void Heap::enter() {
	thread_sync.lock();
}

void Heap::exit() {
	thread_sync.unlock();
}

bool Heap::isMarkAndSweepGC() const {
	return this->gcType != 0;
}

bool Heap::isIncrementalGC() const {
	return this->gcType == 0;
}

void Heap::destroy() {
	delete this->strategy;
	this->strategy = nullptr;
}
//---public method


//protected method---
void Heap::execImpl(int id) {
	if (locked()) {
		return;
	}
	TimeSpan span = TimeSpan();
	int items = getCurrentSize();
	span.start();
	locks++;
	Heap* const h = this;
	if (id == 0) strategy->miniGC(h);
	else if (id == 1) strategy->fullGC(h);
	locks--;
	span.end();
	//削除数と経過時間の表示
	int diff = items - getCurrentSize();
	if (diff > 0 && gcReport) {
		auto ss = std::stringstream();
		ss << "all:" << getCurrentSize() << " ";
		ss << "diff:" << diff << " ";
		ss << "ms:";
		span.print(ss.str());
	}
}

bool Heap::locked() {
	return locks > 0;
}
//---protected method


//private method---
void Heap::do_codeblock(std::vector<CodeBlock*> rootBlockVec, std::function<void(CodeBlock*)> f) {
	for (int i = 0; i < rootBlockVec.size(); i++) {
		f(rootBlockVec.at(i));
	}
}

Heap::Heap() {
	UserSystem* uSys = UserSystem::getInstance();
	this->objects = std::vector<Object_*>();
	this->heapThreshold = uSys->value<int>(UserSystem::GC_THRESHOLD, 64);
	this->gcReport = uSys->value<bool>(UserSystem::GC_REPORT, false);
	this->gcAlways = uSys->value<bool>(UserSystem::GC_ALWAYS, true);
	this->initThr = heapThreshold;
	this->gcType = uSys->value<int>(UserSystem::GC_TYPE, 0);
	if (gcType == 0) {
		this->strategy = new IncrementalGCStrategy();
	} else {
		this->strategy = new MarkAndSweepGCStrategy();
	}
}
//---private method
