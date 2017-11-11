#include "MenuBarNewExecutor.h"
#include "../../../wxgui/MenuBar.h"
#include "../../../env/user/UserMenuBar.h"

//public method---
MenuBarNewExecutor::MenuBarNewExecutor() {
}

MenuBarNewExecutor::~MenuBarNewExecutor() {
}

Object_ * const MenuBarNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * MenuBarNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	return new UserMenuBar(new MenuBar());
}
//---public method
