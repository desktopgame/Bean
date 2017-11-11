#include "MutexLockExecutor.h"
#include "../../user/UserMutex.h"

//public method---
MutexLockExecutor::MutexLockExecutor() {
}

MutexLockExecutor::~MutexLockExecutor() {
}

Object_ * const MutexLockExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMutex* um = static_cast<UserMutex*>(invoker);
	um->lock();
	return getNull();
}
//---public mehtod