#include "MathPowExecutor.h"
#include "../../Numeric.h"

//public method---
MathPowExecutor::MathPowExecutor() {
}

MathPowExecutor::~MathPowExecutor() {
}

Object_ * const MathPowExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	Numeric* b = arg_cast(Numeric, 1, "Numeric");
	float fA = a->getCFloat();
	float fB = b->getCFloat();
	float C = powf(fA, fB);
	return Numeric::newFloat(C);
}
//---public method