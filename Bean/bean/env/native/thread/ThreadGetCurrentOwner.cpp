#include "ThreadGetCurrentOwner.h"
#include "../../user/UserThread.h"

//public method---
ThreadGetCurrentOwner::ThreadGetCurrentOwner() {
}

ThreadGetCurrentOwner::~ThreadGetCurrentOwner() {
}

Object_ * const ThreadGetCurrentOwner::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return UserThread::getCurrent();
}
//---public method