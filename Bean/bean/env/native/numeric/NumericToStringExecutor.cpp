#include "NumericToStringExecutor.h"

//public method---
NumericToStringExecutor::NumericToStringExecutor() {
}

NumericToStringExecutor::~NumericToStringExecutor() {
}

Object_ * const NumericToStringExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* obj = invoker;
	Numeric* numeric = obj->asNumeric();
	String* numStr = String::allocString(numeric->toString());
	Object_* ret = numStr;
	return ret;
}
//---public method