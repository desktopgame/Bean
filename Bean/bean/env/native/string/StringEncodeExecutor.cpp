#include "StringEncodeExecutor.h"

//public method---
StringEncodeExecutor::StringEncodeExecutor() {
}

StringEncodeExecutor::~StringEncodeExecutor() {
}

Object_ * const StringEncodeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	String* type = arg_cast(String, 0, "String");
	return src->encode(*type->getCString());
}
//---public method