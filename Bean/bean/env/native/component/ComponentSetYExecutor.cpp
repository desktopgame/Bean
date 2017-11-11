#include "ComponentSetYExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetYExecutor::ComponentSetYExecutor() {
}

ComponentSetYExecutor::~ComponentSetYExecutor() {
}

Object_ * const ComponentSetYExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	Numeric* ny = arg_cast(Numeric, 0, "Numeric");
	uc->setY(ny->getCInt());
	return getNull();
}
//---public method
