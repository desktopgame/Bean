#include "ButtonRemovePushListenerAtExecutor.h"
#include "../../Numeric.h"
#include "../../user/UserButton.h"

//public method---
ButtonRemovePushListenerAtExecutor::ButtonRemovePushListenerAtExecutor() {
}

ButtonRemovePushListenerAtExecutor::~ButtonRemovePushListenerAtExecutor() {
}

Object_ * const ButtonRemovePushListenerAtExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	UserButton* ub = static_cast<UserButton*>(invoker);
	if (Exception::checkIndexRange(index, 0, ub->getPushListenerCount() - 1)) {
		return getNull();
	}
	ub->removePushListenerAt(index->getCInt());
	return getNull();
}
//---public method