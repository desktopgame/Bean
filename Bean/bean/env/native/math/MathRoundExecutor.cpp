#include "MathRoundExecutor.h"
#include "../../Numeric.h"

//public method---
MathRoundExecutor::MathRoundExecutor() {
}

MathRoundExecutor::~MathRoundExecutor() {
}

Object_ * const MathRoundExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = roundf(a->getCFloat());
	return Numeric::newFloat(f);
}
//---public method