#include "MenuBarGetMenuCountExecutor.h"
#include "../../../env/user/UserMenuBar.h"

//public method---
MenuBarGetMenuCountExecutor::MenuBarGetMenuCountExecutor() {
}

MenuBarGetMenuCountExecutor::~MenuBarGetMenuCountExecutor() {
}

Object_ * const MenuBarGetMenuCountExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenuBar* menubar = static_cast<UserMenuBar*>(invoker);
	return getInteger(menubar->getMenuCount());
}
//---public method