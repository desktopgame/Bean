#include "MenuRemoveSubElementAtExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserMenu.h"

//public method---
MenuRemoveSubElementAtExecutor::MenuRemoveSubElementAtExecutor() {
}

MenuRemoveSubElementAtExecutor::~MenuRemoveSubElementAtExecutor() {
}

Object_ * const MenuRemoveSubElementAtExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenu* menu = static_cast<UserMenu*>(invoker);
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	int max = menu->getSubElementCount() - 1;
	/*
	if (throw_if_overrange(
		index, 
		0, 
		max, 
		message_overrange(index, 0, max)
	)) {
		return getNull();
	}
	*/
	menu->removeSubElementAt(index->getCInt());
	return getNull();
}
//---public method
