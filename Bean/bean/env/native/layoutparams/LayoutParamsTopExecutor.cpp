#include "LayoutParamsTopExecutor.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutParamsTopExecutor::LayoutParamsTopExecutor() {
}

LayoutParamsTopExecutor::~LayoutParamsTopExecutor() {
}

Object_ * const LayoutParamsTopExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutParams* params = static_cast<UserLayoutParams*>(invoker);
	params->top();
	return invoker;
}
//---public method