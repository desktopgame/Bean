#include "MenuNewExecutor.h"
#include "../../../env/user/UserMenu.h"
//#include "../../../wxgui/Menu.h"

//public method---
MenuNewExecutor::MenuNewExecutor() {
}

MenuNewExecutor::~MenuNewExecutor() {
}

Object_ * const MenuNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * MenuNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	String* text = arg_cast(String, 0, "String");
	UserMenu* menu = new UserMenu();
	menu->setText(*text->getCString());
	return menu;
}
//---public method