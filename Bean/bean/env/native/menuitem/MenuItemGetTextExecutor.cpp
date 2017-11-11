#include "MenuItemGetTextExecutor.h"
#include "../../../env/user/UserMenuElement.h"

//public method---
MenuItemGetTextExecutor::MenuItemGetTextExecutor() {
}

MenuItemGetTextExecutor::~MenuItemGetTextExecutor() {
}

Object_ * const MenuItemGetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenuElement* elem = static_cast<UserMenuElement*>(invoker);
	return String::allocString(elem->getText());
}
//---public method