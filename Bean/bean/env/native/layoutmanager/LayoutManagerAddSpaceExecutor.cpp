#include "LayoutManagerAddSpaceExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
LayoutManagerAddSpaceExecutor::LayoutManagerAddSpaceExecutor() {
}

LayoutManagerAddSpaceExecutor::~LayoutManagerAddSpaceExecutor() {
}

Object_ * const LayoutManagerAddSpaceExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	Numeric* size = arg_cast(Numeric, 0, "Numeric");
	layoutMgr->addSpace(size->getCInt());
	return invoker;
}
//---public method
