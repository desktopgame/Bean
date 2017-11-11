#include "StringIndexOfExecutor.h"
#include <unicode/unistr.h>
#include "../../Numeric.h"
#include "../../String.h"

//public method---
StringIndexOfExecutor::StringIndexOfExecutor() {
}

StringIndexOfExecutor::~StringIndexOfExecutor() {
}

Object_ * const StringIndexOfExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	String* find = arg_cast(String, 0, "String");
	return src->indexOf(find);
}
//---public method
