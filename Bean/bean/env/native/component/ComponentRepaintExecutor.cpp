#include "ComponentRepaintExecutor.h"
#include "../../../env/user/UserComponent.h"

//public method---
ComponentRepaintExecutor::ComponentRepaintExecutor() {
}

ComponentRepaintExecutor::~ComponentRepaintExecutor() {
}

Object_ * const ComponentRepaintExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserComponent* uc = dynamic_cast<UserComponent*>(invoker);
	uc->repaint();
	return getNull();
}
//---public method