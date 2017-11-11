#include "ThreadGetNameExecutor.h"
#include "../../String.h"
#include "../../user/UserThread.h"

//public method---
ThreadGetNameExecutor::ThreadGetNameExecutor() {
}

ThreadGetNameExecutor::~ThreadGetNameExecutor() {
}

Object_ * const ThreadGetNameExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* o = invoker;
	UserThread* uth = o->asUserThread();
	std::string name = uth->getThread()->getName();
	return String::allocString(name);
}
//---public method
