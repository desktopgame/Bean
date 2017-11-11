#include "FilePtrReadExecutor.h"

//public method---
FilePtrReadExecutor::FilePtrReadExecutor() {
}

FilePtrReadExecutor::~FilePtrReadExecutor() {
}

Object_ * const FilePtrReadExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getNull();
}
//---public method