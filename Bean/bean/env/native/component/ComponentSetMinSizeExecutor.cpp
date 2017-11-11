#include "ComponentSetMinSizeExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetMinSizeExecutor::ComponentSetMinSizeExecutor() {
}

ComponentSetMinSizeExecutor::~ComponentSetMinSizeExecutor() {
}

Object_ * const ComponentSetMinSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* w = arg_cast(Numeric, 0, "Numeric");
	Numeric* h = arg_cast(Numeric, 1, "Numeric");
	UserComponent* c = static_cast<UserComponent*>(invoker);
	c->setMinSize(wxSize(w->getCInt(), h->getCInt()));
	return getNull();
}
//---public method
