#include "MenuAddMenuItemExecutor.h"
#include "../../../env/user/UserMenu.h"
#include "../../../env/user/UserMenuElement.h"
#include "../../../env/user/UserMenuItem.h"

//public method---
MenuAddMenuItemExecutor::MenuAddMenuItemExecutor() {
}

MenuAddMenuItemExecutor::~MenuAddMenuItemExecutor() {
}

Object_ * const MenuAddMenuItemExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenu* menu = static_cast<UserMenu*>(invoker);
	String* label = arg_cast(String, 0, "String");
	wxMenuItem* item = menu->addMenuItem(*label->getCString());
	return new UserMenuItem(item);
}
//---public method
