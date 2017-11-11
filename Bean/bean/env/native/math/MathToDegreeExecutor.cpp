#include "MathToDegreeExecutor.h"
#include "../../Numeric.h"

//public method---
MathToDegreeExecutor::MathToDegreeExecutor() {
}

MathToDegreeExecutor::~MathToDegreeExecutor() {
}

Object_ * const MathToDegreeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	//http://www.c-tipsref.com/tips/math/o_toang.html
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	float f = a->getCFloat() * 180.0 / (atan(1.0) * 4.0);
	return Numeric::newFloat(f);
}
//---public method