#include "MathTanExecutor.h"
#include "../../Numeric.h"

//public method---
MathTanExecutor::MathTanExecutor() {
}

MathTanExecutor::~MathTanExecutor() {
}

Object_ * const MathTanExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = tanf(a->getCFloat());
	return Numeric::newFloat(f);
}
//---public method