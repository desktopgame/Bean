#include "StringSubstringExecutor.h"
#include "../../Numeric.h"
#include "../../String.h"

//public method---
StringSubstringExecutor::StringSubstringExecutor() {
}

StringSubstringExecutor::~StringSubstringExecutor() {
}

Object_ * const StringSubstringExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	Numeric* offset = arg_cast(Numeric, 0, "Integer");
	Numeric* length = arg_cast(Numeric, 1, "Integer");
	return src->substring(offset->getCInt(), length->getCInt());
}
//---public method
