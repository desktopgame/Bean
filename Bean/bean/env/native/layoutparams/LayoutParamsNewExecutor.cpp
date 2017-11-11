#include "LayoutParamsNewExecutor.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutParamsNewExecutor::LayoutParamsNewExecutor() {
}

LayoutParamsNewExecutor::~LayoutParamsNewExecutor() {
}

Object_ * const LayoutParamsNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return new UserLayoutParams();
}

Object_ * LayoutParamsNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	return new UserLayoutParams();
}
//---public method