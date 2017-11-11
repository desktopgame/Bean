#include "FileGetChildrenExecutor.h"
#include "../../Boolean.h"
#include "../../String.h"
#include "../../user/UserArray.h"
#include "../../../util/IO.h"

//public method---
FileGetChildrenExecutor::FileGetChildrenExecutor() {
}

FileGetChildrenExecutor::~FileGetChildrenExecutor() {
}

Object_ * const FileGetChildrenExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* path = arg_cast(String, 0, "String");
	Boolean* allSubTreeB = arg_cast(Boolean, 1, "Boolean");
	try {
		std::vector<std::string> children = IO::getChildren(
			*path->getCString(),
			allSubTreeB->of()
			);
		auto a =  UserArray::fromVector<std::string>(children, [](std::string s) {
			return String::allocString(s);
		});
		return a;
	} catch (boost::filesystem::filesystem_error e) {
		throw_io_error(proxy, e);
	}
}
//---public method
