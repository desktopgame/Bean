#include "Runtime.h"
#include "Object_.h"
#include "gc/Heap.h"

Runtime* Runtime::current = nullptr;
int Runtime::index = 0;

//public method---
Runtime::Runtime() {
	this->id = Runtime::index++;
}

Runtime::~Runtime() {
}

Runtime * const Runtime::getCurrent() {
	return current;
}

ThreadSPtr Runtime::newThread(std::string name) {
	Runtime* c = getCurrent();
	ThreadSPtr th = std::make_shared<Thread>(name, c->getID());
	th->registerThread();
	return th;
}

void Runtime::exec(std::string mainFile) {
	if (Runtime::current != nullptr) {
		throw std::logic_error("Runtime‚ð•½s‚µ‚ÄŽÀs‚·‚é‚±‚Æ‚Ío—ˆ‚Ü‚¹‚ñ");
	}
	Runtime::current = this;
	execImpl(mainFile);
	Block::blocks_page_clearAll();
	Heap::getInstance()->fullGC();
	Thread::destroy(getID());
	Runtime::current = nullptr;
}

int Runtime::getID() const {
	return this->id;
}
//---public method


//private method---
void Runtime::execImpl(std::string mainFile) {
	Thread::getSystemThread()->registerThread();
	Thread::getSystemThread()->start(mainFile);
	//delete root;
}
//---private method
