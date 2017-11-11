#include "LayoutManagerDoLayoutExecutor.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
LayoutManagerDoLayoutExecutor::LayoutManagerDoLayoutExecutor() {
}

LayoutManagerDoLayoutExecutor::~LayoutManagerDoLayoutExecutor() {
}

Object_ * const LayoutManagerDoLayoutExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	layoutMgr->doLayout();
	return getNull();
}
//---public method