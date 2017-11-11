#include "MenuBarAddMenuExecutor.h"
#include "../../../env/user/UserMenu.h"
#include "../../../env/user/UserMenuBar.h"

//public method---
MenuBarAddMenuExecutor::MenuBarAddMenuExecutor() {
}

MenuBarAddMenuExecutor::~MenuBarAddMenuExecutor() {
}

Object_ * const MenuBarAddMenuExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenuBar* menuBar = static_cast<UserMenuBar*>(invoker);
	String* label = arg_cast(String, 0, "String");
	wxMenu* menu = menuBar->addMenu(*label->getCString());
	return new UserMenu(menu);
}
//---public method
