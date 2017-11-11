#include "FileWriteTextExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileWriteTextExecutor::FileWriteTextExecutor() {
}

FileWriteTextExecutor::~FileWriteTextExecutor() {
}

Object_ * const FileWriteTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	String* content = arg_cast(String, 1, "String");
	do_io(proxy, [path, content]() {
		IO::writeText(*path->getCString(), *content->getBString());
	});
	return getNull();
}
//---public method