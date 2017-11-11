#include "MathFloorExecutor.h"
#include "../../Numeric.h"

//public method---
MathFloorExecutor::MathFloorExecutor() {
}

MathFloorExecutor::~MathFloorExecutor() {
}

Object_ * const MathFloorExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = floorf(a->getCFloat());
	return Numeric::newFloat(f);
}
//---public method