#include "MenuBarRemoveMenuAtExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserMenuBar.h"

//public method---
MenuBarRemoveMenuAtExecutor::MenuBarRemoveMenuAtExecutor() {
}

MenuBarRemoveMenuAtExecutor::~MenuBarRemoveMenuAtExecutor() {
}

Object_ * const MenuBarRemoveMenuAtExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenuBar* menubar = static_cast<UserMenuBar*>(invoker);
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	menubar->removeMenuAt(index->getCInt());
	return getNull();
}
//---public method
