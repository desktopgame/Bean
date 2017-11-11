#include "FileGetNameExecutor.h"
#include "../../../util/IO.h"
//public method---
FileGetNameExecutor::FileGetNameExecutor() {
}

FileGetNameExecutor::~FileGetNameExecutor() {
}
Object_ * const FileGetNameExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	return String::allocString(IO::getName(*path->getCString()));
}
//---public method