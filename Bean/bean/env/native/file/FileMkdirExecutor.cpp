#include "FileMkdirExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileMkdirExecutor::FileMkdirExecutor() {
}

FileMkdirExecutor::~FileMkdirExecutor() {
}

Object_ * const FileMkdirExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* dirName = arg_cast(String, 0, "String");
	do_io(proxy, [dirName]() { IO::mkdir(*dirName->getCString()); });
	return getNull();
}
//---public method