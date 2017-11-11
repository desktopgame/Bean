#include "MenuItemNewExecutor.h"
#include "../../../env/user/UserMenuItem.h"

//public method---
MenuItemNewExecutor::MenuItemNewExecutor() {
}

MenuItemNewExecutor::~MenuItemNewExecutor() {
}

Object_ * const MenuItemNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * MenuItemNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	UserMenuItem* item = new UserMenuItem();
	String* text = arg_cast(String, 0, "String");
	item->setText(*text->getCString());
	return item;
}
//---public method