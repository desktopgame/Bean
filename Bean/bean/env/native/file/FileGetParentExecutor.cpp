#include "FileGetParentExecutor.h"
#include "../../../util/IO.h"

//public method---
FileGetParentExecutor::FileGetParentExecutor() {
}

FileGetParentExecutor::~FileGetParentExecutor() {
}

Object_ * const FileGetParentExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	std::string parent = "";
	do_io(proxy, [&parent, &path]() {
		parent = IO::getParent(*path->getCString());
	});
	return String::allocString(parent);
}
//---public method