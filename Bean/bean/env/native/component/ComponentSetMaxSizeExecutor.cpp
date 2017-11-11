#include "ComponentSetMaxSizeExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetMaxSizeExecutor::ComponentSetMaxSizeExecutor() {
}

ComponentSetMaxSizeExecutor::~ComponentSetMaxSizeExecutor() {
}

Object_ * const ComponentSetMaxSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* c = static_cast<UserComponent*>(invoker);
	Numeric* w = arg_cast(Numeric, 0, "Numeric");
	Numeric* h = arg_cast(Numeric, 1, "Numeric");
	c->setMaxSize(wxSize(w->getCInt(), h->getCInt()));
	return getNull();
}
//---public method
