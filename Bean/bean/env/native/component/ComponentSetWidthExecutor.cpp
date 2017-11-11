#include "ComponentSetWidthExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetWidthExecutor::ComponentSetWidthExecutor() {
}

ComponentSetWidthExecutor::~ComponentSetWidthExecutor() {
}

Object_ * const ComponentSetWidthExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	Numeric* nw = arg_cast(Numeric, 0, "Numeric");
	uc->setWidth(nw->getCInt());
	return getNull();
}
//---public method
