#include "StringLastIndexOfExecutor.h"
#include "../../Numeric.h"

//public method---
StringLastIndexOfExecutor::StringLastIndexOfExecutor() {
}

StringLastIndexOfExecutor::~StringLastIndexOfExecutor() {
}

Object_ * const StringLastIndexOfExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	String* find = arg_cast(String, 0, "String");
	return src->lastIndexOf(find);
}
//---public method