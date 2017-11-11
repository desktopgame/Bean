#include "FileGetCurrentPathExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileGetCurrentPathExecutor::FileGetCurrentPathExecutor() {
}

FileGetCurrentPathExecutor::~FileGetCurrentPathExecutor() {
}

Object_ * const FileGetCurrentPathExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	try {
		String* str = String::allocString(IO::getCurrentPath());
		return str;
	} catch (boost::filesystem::filesystem_error e) {
		throw_io_error(proxy, e);
	}
}
//---public method