#include "ComponentGetXExecutor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetXExecutor::ComponentGetXExecutor() {
}

ComponentGetXExecutor::~ComponentGetXExecutor() {
}

Object_ * const ComponentGetXExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	int x = uc->getX();
	return getInteger(x);
}
//---public method