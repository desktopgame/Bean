#include "LayoutManagerAddStretchExecutor.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
LayoutManagerAddStretchExecutor::LayoutManagerAddStretchExecutor() {
}

LayoutManagerAddStretchExecutor::~LayoutManagerAddStretchExecutor() {
}

Object_ * const LayoutManagerAddStretchExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	layoutMgr->addStretch();
	return invoker;
}
//---public method