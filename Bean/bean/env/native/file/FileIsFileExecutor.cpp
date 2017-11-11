#include "FileIsFileExecutor.h"
#include "../../String.h"
#include "../../../util/IO.h"

//public method---
FileIsFileExecutor::FileIsFileExecutor() {
}

FileIsFileExecutor::~FileIsFileExecutor() {
}

Object_ * const FileIsFileExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	try {
		String* path = arg_cast(String, 0, "String");
		return getBoolean(IO::isFile(*path->getCString()));
	} catch (boost::filesystem::filesystem_error e) {
		throw_io_error(proxy, e);
	}
}
//---public method