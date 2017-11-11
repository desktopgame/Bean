#include "NumericOpModExecutor.h"
#include "../../Numeric.h"

//public method---
NumericOpModExecutor::NumericOpModExecutor() {
}

NumericOpModExecutor::~NumericOpModExecutor() {
}

Object_ * const NumericOpModExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* left = invoker->asNumeric();
	Numeric* right = arg_cast(Numeric, 0, "Numeric");
	Object_* o = left->mod(right);
	return o;
}
//---public method