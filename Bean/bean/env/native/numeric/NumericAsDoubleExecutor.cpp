#include "NumericAsDoubleExecutor.h"
#include "../../Numeric.h"

//public method---
NumericAsDoubleExecutor::NumericAsDoubleExecutor() {
}

NumericAsDoubleExecutor::~NumericAsDoubleExecutor() {
}

Object_ * const NumericAsDoubleExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* self = arg_cast(Numeric, 0, "Numeric");
	return Numeric::newDouble(self->getCDouble());
}
//---public method