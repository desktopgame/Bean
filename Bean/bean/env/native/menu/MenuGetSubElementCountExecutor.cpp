#include "MenuGetSubElementCountExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserMenu.h"

//public method---
MenuGetSubElementCountExecutor::MenuGetSubElementCountExecutor() {
}

MenuGetSubElementCountExecutor::~MenuGetSubElementCountExecutor() {
}
Object_ * const MenuGetSubElementCountExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenu* menu = static_cast<UserMenu*>(invoker);
	Numeric* n = Numeric::newInteger(menu->getSubElementCount());
	return n;
}
//---public method
