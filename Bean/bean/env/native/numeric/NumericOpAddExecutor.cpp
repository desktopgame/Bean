#include "NumericOpAddExecutor.h"
#include "../../Numeric.h"
#include "../../String.h"

//public method---
NumericOpAddExecutor::NumericOpAddExecutor() {
}

NumericOpAddExecutor::~NumericOpAddExecutor() {
}

Object_ * const NumericOpAddExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* left = invoker->asNumeric();
	Object_* o = left->add(args.at(0));
	return o;
}
//---public method