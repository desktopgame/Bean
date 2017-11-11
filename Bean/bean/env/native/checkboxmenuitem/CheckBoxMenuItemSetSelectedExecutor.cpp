#include "CheckBoxMenuItemSetSelectedExecutor.h"
#include "../../../env/user/UserMenuItem.h"

//public method---
CheckBoxMenuItemSetSelectedExecutor::CheckBoxMenuItemSetSelectedExecutor() {
}

CheckBoxMenuItemSetSelectedExecutor::~CheckBoxMenuItemSetSelectedExecutor() {
}

Object_ * const CheckBoxMenuItemSetSelectedExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenuItem* item = static_cast<UserMenuItem*>(invoker);
	return getBoolean(item->isSelected());
}
//---public method