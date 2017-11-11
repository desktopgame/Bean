#include "LayoutParamsFillExecutor.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutParamsFillExecutor::LayoutParamsFillExecutor() {
}

LayoutParamsFillExecutor::~LayoutParamsFillExecutor() {
}

Object_ * const LayoutParamsFillExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutParams* params = static_cast<UserLayoutParams*>(invoker);
	params->fill();
	return invoker;
}
//---public method