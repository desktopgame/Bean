#include "NumericOpMulExecutor.h"
#include "../../Numeric.h"

//public method---
NumericOpMulExecutor::NumericOpMulExecutor() {
}

NumericOpMulExecutor::~NumericOpMulExecutor() {
}

Object_ * const NumericOpMulExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* left = invoker->asNumeric();
	Numeric* right = arg_cast(Numeric, 0, "Numeric");
	Object_* o = left->mul(right);
	return o;
}
//---public method