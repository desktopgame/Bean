#include "ComponentGetYExecutor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetYExecutor::ComponentGetYExecutor() {
}

ComponentGetYExecutor::~ComponentGetYExecutor() {
}

Object_ * const ComponentGetYExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	int y = uc->getY();
	return getInteger(y);
}
//---public method