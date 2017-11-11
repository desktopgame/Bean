#include "ButtonSetTextExecutor.h"
#include "../../../env/String.h"
#include "../../../env/user/UserButton.h"

//public method---
ButtonSetTextExecutor::ButtonSetTextExecutor() {
}

ButtonSetTextExecutor::~ButtonSetTextExecutor() {
}

Object_ * const ButtonSetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserButton* button = static_cast<UserButton*>(invoker);
	String* str = arg_cast(String, 0, "String");
	button->setText(*str->getCString());
	return getNull();
}
//---public method