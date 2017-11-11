#include "LayoutManagerRemoveComponentAtExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
LayoutManagerRemoveComponentAtExecutor::LayoutManagerRemoveComponentAtExecutor() {
}

LayoutManagerRemoveComponentAtExecutor::~LayoutManagerRemoveComponentAtExecutor() {
}

Object_ * const LayoutManagerRemoveComponentAtExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	layoutMgr->removeComponentAt(index->getCInt());
	return getNull();
}
//---public method
