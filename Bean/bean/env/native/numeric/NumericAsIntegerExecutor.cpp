#include "NumericAsIntegerExecutor.h"
#include "../../Numeric.h"

//public method---
NumericAsIntegerExecutor::NumericAsIntegerExecutor() {
}

NumericAsIntegerExecutor::~NumericAsIntegerExecutor() {
}

Object_ * const NumericAsIntegerExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* self = arg_cast(Numeric, 0, "Numeric");
	return Numeric::newInteger(self->getCInt());
}
//---public method