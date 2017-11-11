#include "ComponentSetHeightExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetHeightExecutor::ComponentSetHeightExecutor() {
}

ComponentSetHeightExecutor::~ComponentSetHeightExecutor() {
}

Object_ * const ComponentSetHeightExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	Numeric* nh = arg_cast(Numeric, 0, "Numeric");
	uc->setHeight(nh->getCInt());
	return getNull();
}
//---public method
