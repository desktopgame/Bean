#include "MenuItemSetTextExecutor.h"
#include "../../../env/user/UserMenuElement.h"

//public method---
MenuItemSetTextExecutor::MenuItemSetTextExecutor() {
}

MenuItemSetTextExecutor::~MenuItemSetTextExecutor() {
}

Object_ * const MenuItemSetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenuElement* elem = static_cast<UserMenuElement*>(invoker);
	String* text = arg_cast(String, 0, "String");
	elem->setText(*text->getCString());
	return getNull();
}
//---public method