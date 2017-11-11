#include "MathSinExecutor.h"
#include "../../Numeric.h"

//public method---
MathSinExecutor::MathSinExecutor() {
}

MathSinExecutor::~MathSinExecutor() {
}

Object_ * const MathSinExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = sinf(a->getCFloat());
	return Numeric::newFloat(f);
}
//---public method