#include "FileExistsExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileExistsExecutor::FileExistsExecutor() {
}

FileExistsExecutor::~FileExistsExecutor() {
}

Object_ * const FileExistsExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	return getBoolean(IO::isExists(*path->getCString()));
}
//---public method