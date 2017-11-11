#include "Block.h"
#include <algorithm>
#include "Heap.h"
#include "HeapMutexLock.h"
#include "Page.h"
#include "../Class.h"
#include "../ClassLoader.h"
#include "../Object_.h"
#include "../../Debug.h"
#include "../../threads/Thread.h"

std::vector<BlockSPtr> Block::async_blocks = std::vector<BlockSPtr>();
std::recursive_mutex Block::aync_sync;
//public method---
Block::Block() {
	this->pageStack = std::vector<PageSPtr>();
}

Block::~Block() {
	Debug::break_if(!pageStack.empty());
	pageStack.clear();
}

BlockSPtr Block::getInstance() {
	std::lock_guard<std::recursive_mutex> lock(Block::aync_sync);
	if (!Block::async_blocks.empty()) {
		return Block::async_blocks.back();
	}
	auto currentThread = Thread::getCurrentOrSystem();
	auto classLoader = currentThread->getCurrentClassLoader();
	return currentThread->getBuffer();
}

void Block::pushCurrent() {
	HeapMutexLock hml = HeapMutexLock();
	getInstance()->push();
}

void Block::popCurrent() {
	HeapMutexLock hml = HeapMutexLock();
	getInstance()->pop();
}

void Block::entry(Object_ * obj) {
	BlockSPtr block = getInstance();
	if (block->pageStack.empty()) {
		return;
	}
	block->pageStack.back()->remove(obj);
	block->pageStack.back()->add(obj);
}

void Block::blocks_page_clearAll() {
	do_all_blocks([](BlockSPtr block) {
		block->page_clearAll();
	});
}

void Block::blocks_page_paintAll(GCProgress progress) {
	do_all_blocks([progress](BlockSPtr block) {
		block->page_paintAll(progress);
	});
}

void Block::blocks_page_markAll() {
	do_all_blocks([](BlockSPtr block) {
		block->page_markAll();
	});
}

void Block::blocks_page_remove(Object_ * obj) {
	do_all_blocks([obj](BlockSPtr block) {
		block->page_remove(obj);
	});
}

void Block::startAsync() {
	if (Heap::getInstance()->isMarkAndSweepGC()) {
		return;
	}
	Block::aync_sync.lock();
	Block::async_blocks.push_back(std::make_shared<Block>());
}

void Block::endAsync() {
	if (Heap::getInstance()->isMarkAndSweepGC()) {
		return;
	}
	Block::aync_sync.unlock();
	Block::async_blocks.pop_back();
}

void Block::push() {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	auto page = std::make_shared<Page>(pageStack.size() + 1);
	pageStack.push_back(page);
}

void Block::pop() {
	//std::cout << "stack " << pageStack.size() << std::endl;
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	//––”ö‚Ì—v‘f‚ðŽæ‚èœ‚­
	PageSPtr top = pageStack.back();
	pageStack.pop_back();
	if (pageStack.empty()) {
		top->fix();
	} else {
		top->fix(pageStack.back());
	}
}

bool Block::recordObject(Object_* obj) {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	if (pageStack.empty()) {
		return false;
	}
	pageStack.back()->add(obj);
	return true;
}

void Block::page_remove(Object_ * obj) {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	for (PageSPtr page : this->pageStack) {
		page->remove(obj);
	}
}

void Block::page_markAll() {
	for (PageSPtr page : this->pageStack) {
		page->obj_markAll();
	}
}

void Block::page_clearAll() {
	for (PageSPtr page : this->pageStack) {
		page->obj_clearAll();
	}
}

void Block::page_paintAll(GCProgress progress) {
	for (PageSPtr page : this->pageStack) {
		page->obj_paintAll(progress);
	}
}

int Block::getDepth() const {
	return this->pageStack.size() + 1;
}
//---public method


//private method---
void Block::do_all_blocks(std::function<void(BlockSPtr)> f) {
	std::vector<ThreadSPtr> threads = Thread::getThreads();
	for (ThreadSPtr th : threads) {
		BlockSPtr block = th->getBuffer();
		std::lock_guard<std::recursive_mutex> lock(block->thread_sync);
		f(block);
	}
	for (auto block : Block::async_blocks) {
		std::lock_guard<std::recursive_mutex> lock(block->thread_sync);
		f(block);
	}
}
//---private method
