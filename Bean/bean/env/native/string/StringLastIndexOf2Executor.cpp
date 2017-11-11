#include "StringLastIndexOf2Executor.h"
#include "../../Numeric.h"

//public method---
StringLastIndexOf2Executor::StringLastIndexOf2Executor() {
}

StringLastIndexOf2Executor::~StringLastIndexOf2Executor() {
}

Object_ * const StringLastIndexOf2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	String* find = arg_cast(String, 0, "String");
	Numeric* index = arg_cast(Numeric, 1, "Integer");
	return src->lastIndexOf(find, index->getCInt());
}
//---public method