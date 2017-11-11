#include "StringInsertExecutor.h"
#include "../../Numeric.h"

//public method---
StringInsertExecutor::StringInsertExecutor() {
}

StringInsertExecutor::~StringInsertExecutor() {
}

Object_ * const StringInsertExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	Numeric* offs = arg_cast(Numeric, 0, "Numeric");
	String* app = arg_cast(String, 1, "String");

	return src->insert(offs->getCInt(), app);
}
//---public method