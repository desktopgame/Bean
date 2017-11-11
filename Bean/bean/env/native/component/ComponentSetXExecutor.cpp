#include "ComponentSetXExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetXExecutor::ComponentSetXExecutor() {
}

ComponentSetXExecutor::~ComponentSetXExecutor() {
}

Object_ * const ComponentSetXExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	Numeric* nx = arg_cast(Numeric, 0, "Numeric");
	uc->setX(nx->getCInt());
	return getNull();
}
//---public method
