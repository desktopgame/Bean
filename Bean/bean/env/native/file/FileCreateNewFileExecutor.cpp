#include "FileCreateNewFileExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileCreateNewFileExecutor::FileCreateNewFileExecutor() {
}

FileCreateNewFileExecutor::~FileCreateNewFileExecutor() {
}

Object_ * const FileCreateNewFileExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	do_io(proxy, [&path]() { IO::createNewFile(*path->getCString()); });
	return getNull();
}
//---public method