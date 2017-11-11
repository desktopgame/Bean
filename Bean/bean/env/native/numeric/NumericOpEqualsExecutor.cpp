#include "NumericOpEqualsExecutor.h"
#include "../../Numeric.h"

//public method---
NumericOpEqualsExecutor::NumericOpEqualsExecutor() {
}

NumericOpEqualsExecutor::~NumericOpEqualsExecutor() {
}

Object_ * const NumericOpEqualsExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* left = invoker->asNumeric();
	Numeric* right = arg_cast(Numeric, 0, "Numeric");
	Object_* o = left->equals(right);
	return o;
}
//---public method