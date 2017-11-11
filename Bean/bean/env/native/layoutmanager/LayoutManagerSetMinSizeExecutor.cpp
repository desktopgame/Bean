#include "LayoutManagerSetMinSizeExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
LayoutManagerSetMinSizeExecutor::LayoutManagerSetMinSizeExecutor() {
}

LayoutManagerSetMinSizeExecutor::~LayoutManagerSetMinSizeExecutor() {
}

Object_ * const LayoutManagerSetMinSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = static_cast<UserLayoutManager*>(invoker);
	Numeric* w = arg_cast(Numeric, 0, "Numeric");
	Numeric* h = arg_cast(Numeric, 1, "Numeric");
	wxSize s = wxSize(w->getCInt(), h->getCInt());
	layoutMgr->setMinSize(s);
	return getNull();
}
//---public method
