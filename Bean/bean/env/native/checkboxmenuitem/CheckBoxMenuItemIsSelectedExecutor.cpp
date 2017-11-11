#include "CheckBoxMenuItemIsSelectedExecutor.h"
#include "../../../env/Boolean.h"
#include "../../../env/user/UserMenuItem.h"

//public method---
CheckBoxMenuItemIsSelectedExecutor::CheckBoxMenuItemIsSelectedExecutor() {
}

CheckBoxMenuItemIsSelectedExecutor::~CheckBoxMenuItemIsSelectedExecutor() {
}

Object_ * const CheckBoxMenuItemIsSelectedExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMenuItem* item = static_cast<UserMenuItem*>(invoker);
	Boolean* b = arg_cast(Boolean, 0, "Boolean");
	item->setSelected(b->of());
	return getNull();
}
//---public method
