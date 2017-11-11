#include "ComponentGetForegroundExecutor.h"
#include "../../../env/user/UserColor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetForegroundExecutor::ComponentGetForegroundExecutor() {
}

ComponentGetForegroundExecutor::~ComponentGetForegroundExecutor() {
}

Object_ * const ComponentGetForegroundExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* comp = static_cast<UserComponent*>(invoker);
	return new UserColor(comp->getForeground());
}
//---public method