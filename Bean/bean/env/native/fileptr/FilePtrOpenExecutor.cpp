#include "FilePtrOpenExecutor.h"

//public method---
FilePtrOpenExecutor::FilePtrOpenExecutor() {
}

FilePtrOpenExecutor::~FilePtrOpenExecutor() {
}

Object_ * const FilePtrOpenExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getNull();
}
//---public method