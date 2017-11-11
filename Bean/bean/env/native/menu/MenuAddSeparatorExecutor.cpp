#include "MenuAddSeparatorExecutor.h"
#include "../../../env/user/UserMenu.h"

//public method---
MenuAddSeparatorExecutor::MenuAddSeparatorExecutor() {
}

MenuAddSeparatorExecutor::~MenuAddSeparatorExecutor() {
}
Object_ * const MenuAddSeparatorExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenu* menu = static_cast<UserMenu*>(invoker);
	menu->addSeparator();
	return getNull();
}
//---public method