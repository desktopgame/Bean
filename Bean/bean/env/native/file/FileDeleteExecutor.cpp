#include "FileDeleteExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileDeleteExecutor::FileDeleteExecutor() {
}

FileDeleteExecutor::~FileDeleteExecutor() {
}

Object_ * const FileDeleteExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	do_io(proxy, [&path]() { IO::delete_(*path->getCString()); });
	return getNull();
}
//---public method