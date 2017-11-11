#include "ThreadJoinExecutor.h"
#include "../../../threads/Thread.h"
#include "../../../env/user/UserThread.h"

//public method---
ThreadJoinExecutor::ThreadJoinExecutor() {
}

ThreadJoinExecutor::~ThreadJoinExecutor() {
}

Object_ * const ThreadJoinExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserThread* th = invoker->asUserThread();
	ThreadSPtr thImpl = th->getThread();
	thImpl->join();
	return getNull();
}
//---public method
