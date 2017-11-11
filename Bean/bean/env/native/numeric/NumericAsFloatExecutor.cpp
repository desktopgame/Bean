#include "NumericAsFloatExecutor.h"
#include "../../Numeric.h"

//public method---
NumericAsFloatExecutor::NumericAsFloatExecutor() {
}

NumericAsFloatExecutor::~NumericAsFloatExecutor() {
}

Object_ * const NumericAsFloatExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* self = arg_cast(Numeric, 0, "Numeric");
	return Numeric::newFloat(self->getCFloat());
}
//---public method