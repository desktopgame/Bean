#include "ComponentSetFitSizeExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentSetFitSizeExecutor::ComponentSetFitSizeExecutor() {
}

ComponentSetFitSizeExecutor::~ComponentSetFitSizeExecutor() {
}

Object_ * const ComponentSetFitSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* c = static_cast<UserComponent*>(invoker);
	Numeric* w = arg_cast(Numeric, 0, "Numeric");
	Numeric* h = arg_cast(Numeric, 1, "Numeric");
	c->setFitSize(wxSize(w->getCInt(), h->getCInt()));
	return getNull();
}
//---public method
