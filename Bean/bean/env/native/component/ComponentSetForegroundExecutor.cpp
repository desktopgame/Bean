#include "ComponentSetForegroundExecutor.h"
#include "../../../env/user/UserColor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetForegroundExecutor::ComponentSetForegroundExecutor() {
}

ComponentSetForegroundExecutor::~ComponentSetForegroundExecutor() {
}

Object_ * const ComponentSetForegroundExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserColor* foreColor = arg_cast(UserColor, 0, "Color");
	UserComponent* comp = static_cast<UserComponent*>(invoker);
	comp->setForeground(foreColor->getWXColor());
	return getNull();
}
//---public method