#include "ButtonGetPushListenerCountExecutor.h"
#include "../../user/UserButton.h"

//public method---
ButtonGetPushListenerCountExecutor::ButtonGetPushListenerCountExecutor() {
}

ButtonGetPushListenerCountExecutor::~ButtonGetPushListenerCountExecutor() {
}

Object_ * const ButtonGetPushListenerCountExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserButton* ub = static_cast<UserButton*>(invoker);
	int i = ub->getPushListenerCount();
	return getInteger(i);
}
//---public method