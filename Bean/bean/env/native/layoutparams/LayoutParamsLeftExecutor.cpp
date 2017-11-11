#include "LayoutParamsLeftExecutor.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutParamsLeftExecutor::LayoutParamsLeftExecutor() {
}

LayoutParamsLeftExecutor::~LayoutParamsLeftExecutor() {
}

Object_ * const LayoutParamsLeftExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutParams* params = static_cast<UserLayoutParams*>(invoker);
	params->left();
	return invoker;
}
//---public method