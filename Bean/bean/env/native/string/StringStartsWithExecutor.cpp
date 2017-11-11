#include "StringStartsWithExecutor.h"
#include "../../Boolean.h"

//public method---
StringStartsWithExecutor::StringStartsWithExecutor() {
}

StringStartsWithExecutor::~StringStartsWithExecutor() {
}

Object_ * const StringStartsWithExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	String* find = arg_cast(String, 0, "String");
	return src->startsWith(find);
}
//---public method