#include "ComponentGetHeightExecutor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetHeightExecutor::ComponentGetHeightExecutor() {
}

ComponentGetHeightExecutor::~ComponentGetHeightExecutor() {
}

Object_ * const ComponentGetHeightExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = invoker->asUserComponent();
	int h = uc->getHeight();
	return getInteger(h);
}
//---public method