#include "MathAbsExecutor.h"
#include "../../Numeric.h"

//public method---
MathAbsExecutor::MathAbsExecutor() {
}

MathAbsExecutor::~MathAbsExecutor() {
}

Object_ * const MathAbsExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float fA = abs(a->getCFloat());
	return Numeric::newFloat(fA);
}
//---public method