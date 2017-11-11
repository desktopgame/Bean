#include "ButtonAddPushListenerExecutor.h"
#include "../../user/UserButton.h"
#include "../../user/UserDelegate.h"

//public method---
ButtonAddPushListenerExecutor::ButtonAddPushListenerExecutor() {
}

ButtonAddPushListenerExecutor::~ButtonAddPushListenerExecutor() {
}

Object_ * const ButtonAddPushListenerExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserDelegate* d = arg_cast(UserDelegate, 0, "Delegate");
	UserButton* ub = static_cast<UserButton*>(invoker);
	ub->addPushListener(d);
	return getNull();
}
//---public method
