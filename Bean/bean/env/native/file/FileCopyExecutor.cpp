#include "FileCopyExecutor.h"
#include "../../Numeric.h"
#include "../../../util/IO.h"

//public method---
FileCopyExecutor::FileCopyExecutor() {
}

FileCopyExecutor::~FileCopyExecutor() {
}

Object_ * const FileCopyExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = arg_cast(String, 0, "String");
	String* dst = arg_cast(String, 1, "String");
	Numeric* option = arg_cast(Numeric, 2, "Integer");
	boost::filesystem::copy_option c = boost::filesystem::copy_option::none;
	switch (option->getCInt()) {
		case 0:
			c = boost::filesystem::copy_option::fail_if_exists;
			break;
		case 1:
			c = boost::filesystem::copy_option::overwrite_if_exists;
			break;
	}
	try {
		IO::copy(
			*src->getCString(),
			*dst->getCString(),
			c
		);
	} catch (boost::filesystem::filesystem_error e) {
		throw_io_error(proxy, e);
	}
	return getNull();
}
//---public method