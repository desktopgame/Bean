#include "MenuAddCheckBoxMenuItemExecutor.h"
#include "../../../env/user/UserMenu.h"
#include "../../../env/user/UserMenuItem.h"

//public method---
MenuAddCheckBoxMenuItemExecutor::MenuAddCheckBoxMenuItemExecutor() {
}

MenuAddCheckBoxMenuItemExecutor::~MenuAddCheckBoxMenuItemExecutor() {
}

Object_ * const MenuAddCheckBoxMenuItemExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenu* menu = static_cast<UserMenu*>(invoker);
	String* label = arg_cast(String, 0, "String");
	wxMenuItem* wxmenuitem = menu->addCheckBoxMenuItem(*label->getCString());
	return new UserMenuItem(wxmenuitem);
}
//---public method