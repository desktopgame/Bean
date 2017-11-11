#include "ThreadSleepExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../threads/Thread.h"
#include "../../../env/user/UserThread.h"

//public method---
ThreadSleepExecutor::ThreadSleepExecutor() {
}

ThreadSleepExecutor::~ThreadSleepExecutor() {
}

Object_ * const ThreadSleepExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* millSecNum = arg_cast(Numeric, 0, "Numeric");
	int millSec = millSecNum->getCInt();
	if (millSec == 0) {
		return getNull();
	}
	/*
	//ïâÇÃêîÇ»ÇÁó·äO
	if (throw_if_negative(millSecNum, message_negative(millSecNum))) {
		return getNull();
	}
	*/
	Thread::sleep(millSec);
	return getNull();
}
//---public method
