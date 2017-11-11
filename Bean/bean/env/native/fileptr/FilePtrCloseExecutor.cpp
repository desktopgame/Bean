#include "FilePtrCloseExecutor.h"
//public method---
FilePtrCloseExecutor::FilePtrCloseExecutor() {
}

FilePtrCloseExecutor::~FilePtrCloseExecutor() {
}

Object_ * const FilePtrCloseExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getNull();
}
//---public method