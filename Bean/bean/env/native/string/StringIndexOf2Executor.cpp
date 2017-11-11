#include "StringIndexOf2Executor.h"
#include "../../Numeric.h"

//public method---
StringIndexOf2Executor::StringIndexOf2Executor() {
}

StringIndexOf2Executor::~StringIndexOf2Executor() {
}

Object_ * const StringIndexOf2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	String* find = arg_cast(String, 0, "String");
	Numeric* index = arg_cast(Numeric, 1, "Integer");
	return src->indexOf(find, index->getCInt());
}
//---public method