#include "LayoutParamsCenterExecutor.h"
#include "../../../env/user/UserLayoutParams.h"

//public method--
LayoutParamsCenterExecutor::LayoutParamsCenterExecutor() {
}

LayoutParamsCenterExecutor::~LayoutParamsCenterExecutor() {
}
Object_ * const LayoutParamsCenterExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutParams* params = static_cast<UserLayoutParams*>(invoker);
	params->center();
	return invoker;
}
//---public method