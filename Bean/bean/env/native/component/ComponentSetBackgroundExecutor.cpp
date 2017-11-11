#include "ComponentSetBackgroundExecutor.h"
#include "../../../env/user/UserColor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetBackgroundExecutor::ComponentSetBackgroundExecutor() {
}

ComponentSetBackgroundExecutor::~ComponentSetBackgroundExecutor() {
}

Object_ * const ComponentSetBackgroundExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserColor* backColor = arg_cast(UserColor, 0, "Color");
	UserComponent* comp = static_cast<UserComponent*>(invoker);
	comp->setBackground(backColor->getWXColor());
	return getNull();
}
//---public method