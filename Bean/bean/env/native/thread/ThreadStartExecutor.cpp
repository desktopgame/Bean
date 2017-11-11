#include "ThreadStartExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/ClassLoader.h"
#include "../../../env/Field.h"
#include "../../../threads/Thread.h"
#include "../../../env/user/UserDelegate.h"
#include "../../../env/user/UserThread.h"

//public method---
ThreadStartExecutor::ThreadStartExecutor() {
}

ThreadStartExecutor::~ThreadStartExecutor() {
}

Object_ * const ThreadStartExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserThread* th = invoker->asUserThread();
	ThreadSPtr thImpl = th->getThread();
	if (thImpl->getState() == ThreadState::RUNNING ||
		thImpl->getState() == ThreadState::TERMINATE) {
		throw_simple("api.exc.ThreadStateError", "スレッドを開始出来ません");
		return getNull();
	}
	UserDelegate* d = arg_cast(UserDelegate, 0, "Delegate");
	th->start(d);
	return getNull();
}
//---public method
