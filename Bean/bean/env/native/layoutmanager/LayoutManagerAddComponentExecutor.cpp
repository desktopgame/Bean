#include "LayoutManagerAddComponentExecutor.h"
#include "../../../env/user/UserComponent.h"
#include "../../../env/user/UserLayoutManager.h"
#include "../../../env/user/UserLayoutParams.h"

//public method---
LayoutManagerAddComponentExecutor::LayoutManagerAddComponentExecutor() {
}

LayoutManagerAddComponentExecutor::~LayoutManagerAddComponentExecutor() {
}

Object_ * const LayoutManagerAddComponentExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	UserComponent* c = arg_cast(UserComponent, 0, "Component");
	UserLayoutParams* p = arg_cast(UserLayoutParams, 1, "LayoutParams");
	layoutMgr->addComponent(c->getWX(), *p->getValue());
	return invoker;
}
//---public method
