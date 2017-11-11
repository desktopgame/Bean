#include "StringRemoveExecutor.h"
#include "../../Numeric.h"

//public method---
StringRemoveExecutor::StringRemoveExecutor() {
}

StringRemoveExecutor::~StringRemoveExecutor() {
}

Object_ * const StringRemoveExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* src = invoker->asString();
	Numeric* offs = arg_cast(Numeric, 0, "Integer");
	Numeric* len = arg_cast(Numeric, 1, "Integer");
	return src->remove(offs->getCInt(), len->getCInt());
}
//---public method