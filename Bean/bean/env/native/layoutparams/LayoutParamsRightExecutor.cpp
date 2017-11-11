#include "LayoutParamsRightExecutor.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutParamsRightExecutor::LayoutParamsRightExecutor() {
}

LayoutParamsRightExecutor::~LayoutParamsRightExecutor() {
}

Object_ * const LayoutParamsRightExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutParams* params = static_cast<UserLayoutParams*>(invoker);
	params->right();
	return invoker;
}
//---public method