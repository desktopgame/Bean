#include "ThreadNewExecutor.h"
#include "../../../threads/Thread.h"
#include "../../../env/user/UserThread.h"

//public method---
ThreadNewExecutor::ThreadNewExecutor() {
}

ThreadNewExecutor::~ThreadNewExecutor() {
}

Object_ * const ThreadNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * ThreadNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	String* name = arg_cast(String, 0, "String");
	return new UserThread(*name->getCString());
}
//---public method