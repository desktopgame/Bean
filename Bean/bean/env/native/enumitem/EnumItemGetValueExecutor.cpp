#include "EnumItemGetValueExecutor.h"
#include "../../EnumItem.h"

//public method---
EnumItemGetValueExecutor::EnumItemGetValueExecutor() {
}

EnumItemGetValueExecutor::~EnumItemGetValueExecutor() {
}

Object_ * const EnumItemGetValueExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	ClassSPtr classz = invoker->getClass();
	std::shared_ptr<EnumItem> enumItem = std::dynamic_pointer_cast<EnumItem>(classz);
	return enumItem->getValue();
}
//---public method