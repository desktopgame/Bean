#include "FileReadTextExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileReadTextExecutor::FileReadTextExecutor() {
}

FileReadTextExecutor::~FileReadTextExecutor() {
}

Object_ * const FileReadTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	BString content = BString();
	do_io(proxy, [&content, path] {
		content = IO::readText(*path->getCString());
	});
	return String::allocString(content);
}
//---public method