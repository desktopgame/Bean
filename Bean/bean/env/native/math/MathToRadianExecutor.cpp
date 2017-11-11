#include "MathToRadianExecutor.h"
#include "../../Numeric.h"

//public method---
MathToRadianExecutor::MathToRadianExecutor() {
}

MathToRadianExecutor::~MathToRadianExecutor() {
}

Object_ * const MathToRadianExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	//http://www.c-tipsref.com/tips/math/o_torad.html
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = a->getCFloat() * atan(1.0) * 4.0 / 180.0;
	return Numeric::newFloat(f);
}
//---public method