#include "StringEndsWithExecutor.h"
#include "../../Boolean.h"

//public method---
StringEndsWithExecutor::StringEndsWithExecutor() {
}

StringEndsWithExecutor::~StringEndsWithExecutor() {
}

Object_ * const StringEndsWithExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	String* find = arg_cast(String, 0, "String");
	return src->endsWith(find);
}
//---public method