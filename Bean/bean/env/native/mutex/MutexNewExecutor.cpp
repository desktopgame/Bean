#include "MutexNewExecutor.h"
#include "../../user/UserMutex.h"

//public method---
MutexNewExecutor::MutexNewExecutor() {
}

MutexNewExecutor::~MutexNewExecutor() {
}

Object_ * const MutexNewExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * MutexNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	return new UserMutex();
}
//---public method