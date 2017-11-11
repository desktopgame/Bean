#include "MathSqrtExecutor.h"
#include "../../Numeric.h"

//public method---
MathSqrtExecutor::MathSqrtExecutor() {
}

MathSqrtExecutor::~MathSqrtExecutor() {
}

Object_ * const MathSqrtExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = sqrtf(a->getCFloat());
	return Numeric::newFloat(f);
}
//---public method