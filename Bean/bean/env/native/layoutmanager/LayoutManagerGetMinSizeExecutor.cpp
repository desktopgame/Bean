#include "LayoutManagerGetMinSizeExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
LayoutManagerGetMinSizeExecutor::LayoutManagerGetMinSizeExecutor() {
}

LayoutManagerGetMinSizeExecutor::~LayoutManagerGetMinSizeExecutor() {
}

Object_ * const LayoutManagerGetMinSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	wxSize size = layoutMgr->getMinSize();
	return Class::dynamicNewInstance(
		"api.geom.Size2D", 
		Numeric::newInteger(size.GetWidth()), 
		Numeric::newInteger(size.GetHeight())
	);
}
//---public method
