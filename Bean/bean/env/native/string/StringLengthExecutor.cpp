#include "StringLengthExecutor.h"
#include "../../Numeric.h"
#include "../../String.h"

//public method---
StringLengthExecutor::StringLengthExecutor() {
}

StringLengthExecutor::~StringLengthExecutor() {
}

Object_ * const StringLengthExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return invoker->asString()->length();
}
//---public method
