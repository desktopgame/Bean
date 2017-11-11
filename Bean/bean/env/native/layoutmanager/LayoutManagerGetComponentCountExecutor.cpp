#include "LayoutManagerGetComponentCountExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
LayoutManagerGetComponentCountExecutor::LayoutManagerGetComponentCountExecutor() {
}

LayoutManagerGetComponentCountExecutor::~LayoutManagerGetComponentCountExecutor() {
}

Object_ * const LayoutManagerGetComponentCountExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	Numeric* index = Numeric::newInteger(layoutMgr->getComponentCount());
	return index;
}
//---public method
