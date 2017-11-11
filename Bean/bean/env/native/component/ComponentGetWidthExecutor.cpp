#include "ComponentGetWidthExecutor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetWidthExecutor::ComponentGetWidthExecutor() {
}

ComponentGetWidthExecutor::~ComponentGetWidthExecutor() {
}

Object_ * const ComponentGetWidthExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	int w = uc->getWidth();
	return getInteger(w);
}
//---public method