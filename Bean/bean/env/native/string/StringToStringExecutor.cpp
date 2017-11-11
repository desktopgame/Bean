#include "StringToStringExecutor.h"
#include "../../String.h"
//public method---
StringToStringExecutor::StringToStringExecutor() {
}

StringToStringExecutor::~StringToStringExecutor() {
}

Object_ * const StringToStringExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* obj = invoker;
	String* str = obj->asString();
	String* newStr = String::allocString(*str->getCString());
	return newStr;
}
//---public method