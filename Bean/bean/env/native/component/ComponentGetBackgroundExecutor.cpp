#include "ComponentGetBackgroundExecutor.h"
#include "../../../env/user/UserColor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetBackgroundExecutor::ComponentGetBackgroundExecutor() {
}

ComponentGetBackgroundExecutor::~ComponentGetBackgroundExecutor() {
}

Object_ * const ComponentGetBackgroundExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* comp = static_cast<UserComponent*>(invoker);
	return new UserColor(comp->getBackground());
}
//---public method