#include "LayoutParamsBottomExecutor.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutParamsBottomExecutor::LayoutParamsBottomExecutor() {
}

LayoutParamsBottomExecutor::~LayoutParamsBottomExecutor() {
}

Object_ * const LayoutParamsBottomExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutParams* params = static_cast<UserLayoutParams*>(invoker);
	params->bottom();
	return invoker;
}
//---public method