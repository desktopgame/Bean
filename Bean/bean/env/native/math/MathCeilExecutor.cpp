#include "MathCeilExecutor.h"
#include "../../Numeric.h"

//public method---
MathCeilExecutor::MathCeilExecutor() {
}

MathCeilExecutor::~MathCeilExecutor() {
}

Object_ * const MathCeilExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = ceilf(a->getCFloat());
	return Numeric::newFloat(f);
}
//---public method