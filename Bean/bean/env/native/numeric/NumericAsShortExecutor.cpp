#include "NumericAsShortExecutor.h"
#include "../../Numeric.h"

//public method---
NumericAsShortExecutor::NumericAsShortExecutor() {
}

NumericAsShortExecutor::~NumericAsShortExecutor() {
}

Object_ * const NumericAsShortExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* self = arg_cast(Numeric, 0, "Numeric");
	return Numeric::newShort(self->getCShort());
}
//---public method