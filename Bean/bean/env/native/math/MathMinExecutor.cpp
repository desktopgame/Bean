#include "MathMinExecutor.h"
#include <math.h>
#include "../../Numeric.h"

//public method---
MathMinExecutor::MathMinExecutor() {
}

MathMinExecutor::~MathMinExecutor() {
}

Object_ * const MathMinExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* a = arg_cast(Numeric, 0, "Numeric");
	Numeric* b = arg_cast(Numeric, 1, "Numeric");
	float fA = a->getCFloat();
	float fB = b->getCFloat();
	if (fA < fB) {
		return Numeric::newFloat(fA);
	} else {
		return Numeric::newFloat(fB);
	}
	return nullptr;
}
//---public method