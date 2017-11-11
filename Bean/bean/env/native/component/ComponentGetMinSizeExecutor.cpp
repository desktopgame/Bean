#include "ComponentGetMinSizeExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetMinSizeExecutor::ComponentGetMinSizeExecutor() {
}

ComponentGetMinSizeExecutor::~ComponentGetMinSizeExecutor() {
}

Object_ * const ComponentGetMinSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* c = static_cast<UserComponent*>(invoker);
	wxSize s = c->getMinSize();
	return Class::dynamicNewInstance(
		"api.geom.Size2D",
		getInteger(s.GetWidth()),
		getInteger(s.GetHeight())
	);
}
//---public method
