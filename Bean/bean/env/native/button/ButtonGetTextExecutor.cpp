#include "ButtonGetTextExecutor.h"
#include "../../../env/user/UserButton.h"

//public method---
ButtonGetTextExecutor::ButtonGetTextExecutor() {
}

ButtonGetTextExecutor::~ButtonGetTextExecutor() {
}

Object_ * const ButtonGetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserButton* button = static_cast<UserButton*>(invoker);
	return String::allocString(button->getText());
}
//---public method