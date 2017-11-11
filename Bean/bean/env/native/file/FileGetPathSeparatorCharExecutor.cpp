#include "FileGetPathSeparatorCharExecutor.h"
#include "../../../util/IO.h"

//public method---
FileGetPathSeparatorCharExecutor::FileGetPathSeparatorCharExecutor() {
}

FileGetPathSeparatorCharExecutor::~FileGetPathSeparatorCharExecutor() {
}

Object_ * const FileGetPathSeparatorCharExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	try {
		Object_* ch = getCharacter(IO::getDirectorySeparatorChar());
		return ch;
	} catch (boost::filesystem::filesystem_error e) {
		throw_io_error(proxy, e);
	}
}
//---public method