#include "NumericAsLongExecutor.h"
#include "../../Numeric.h"

//public method---
NumericAsLongExecutor::NumericAsLongExecutor() {
}

NumericAsLongExecutor::~NumericAsLongExecutor() {
}

Object_ * const NumericAsLongExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* self = arg_cast(Numeric, 0, "Numeric");
	return Numeric::newLong(self->getCLong());
}
//---public method