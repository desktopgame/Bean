#include "MutexUnlockExecutor.h"
#include "../../user/UserMutex.h"

//public method---
MutexUnlockExecutor::MutexUnlockExecutor() {
}

MutexUnlockExecutor::~MutexUnlockExecutor() {
}

Object_ * const MutexUnlockExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMutex* um = static_cast<UserMutex*>(invoker);
	um->unlock();
	return getNull();
}
//---public method