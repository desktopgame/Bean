#include "MenuAddMenuExecutor.h"
#include "../../../env/user/UserMenu.h"

//public method---
MenuAddMenuExecutor::MenuAddMenuExecutor() {
}

MenuAddMenuExecutor::~MenuAddMenuExecutor() {
}

Object_ * const MenuAddMenuExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenu* menu = static_cast<UserMenu*>(invoker);
	String* label = arg_cast(String, 0, "String");
	wxMenu* wxmenu = menu->addMenu(*label->getCString());
	return new UserMenu(wxmenu);
}
//---public method