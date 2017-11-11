#include "MathCosExecutor.h"
#include "../../Numeric.h"

//public method---
MathCosExecutor::MathCosExecutor() {
}

MathCosExecutor::~MathCosExecutor() {
}

Object_ * const MathCosExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = cosf(a->getCFloat());
	return Numeric::newFloat(f);
}
//---public method