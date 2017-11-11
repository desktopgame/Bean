#include "EnumItemGetIndexExecutor.h"
#include "../../EnumItem.h"

//public method---
EnumItemGetIndexExecutor::EnumItemGetIndexExecutor() {
}

EnumItemGetIndexExecutor::~EnumItemGetIndexExecutor() {
}

Object_ * const EnumItemGetIndexExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	ClassSPtr classz = invoker->getClass();
	std::shared_ptr<EnumItem> enumItem = std::dynamic_pointer_cast<EnumItem>(classz);
	return getInteger(enumItem->getId());
}
//---public method