#include "NumericOpDivExecutor.h"
#include "../../Numeric.h"

//public method---
NumericOpDivExecutor::NumericOpDivExecutor() {
}

NumericOpDivExecutor::~NumericOpDivExecutor() {
}

Object_ * const NumericOpDivExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* left = invoker->asNumeric();
	Numeric* right = arg_cast(Numeric, 0, "Numeric");
	Object_* o = left->div(right);
	return o;
}
//---public method