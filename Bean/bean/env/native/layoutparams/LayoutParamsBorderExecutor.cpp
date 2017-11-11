#include "LayoutParamsBorderExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutParamsBorderExecutor::LayoutParamsBorderExecutor() {
}

LayoutParamsBorderExecutor::~LayoutParamsBorderExecutor() {
}

Object_ * const LayoutParamsBorderExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutParams* params = static_cast<UserLayoutParams*>(invoker);
	Numeric* thick = arg_cast(Numeric, 0, "Numeric");
	params->border(thick->getCInt());
	return invoker;
}
//---public method
