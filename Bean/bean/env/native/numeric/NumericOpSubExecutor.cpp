#include "NumericOpSubExecutor.h"
#include "../../Numeric.h"
//public method---
NumericOpSubExecutor::NumericOpSubExecutor() {
}

NumericOpSubExecutor::~NumericOpSubExecutor() {
}

Object_ * const NumericOpSubExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* left = invoker->asNumeric();
	Numeric* right = arg_cast(Numeric, 0, "Numeric");
	Object_* o = left->sub(right);
	return o;
}
//---public method