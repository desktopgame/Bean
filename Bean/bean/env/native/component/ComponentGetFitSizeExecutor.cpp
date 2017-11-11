#include "ComponentGetFitSizeExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentGetFitSizeExecutor::ComponentGetFitSizeExecutor() {
}

ComponentGetFitSizeExecutor::~ComponentGetFitSizeExecutor() {
}

Object_ * const ComponentGetFitSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* c = static_cast<UserComponent*>(invoker);
	wxSize s = c->getFitSize();
	return Class::dynamicNewInstance(
		"api.geom.Size2D",
		getInteger(s.GetWidth()),
		getInteger(s.GetHeight())
	);
}
//---public method
