#include "FlowLayoutNewHorizontalExecutor.h"
#include "../../../wxgui/LayoutManager.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
FlowLayoutNewHorizontalExecutor::FlowLayoutNewHorizontalExecutor() {
}

FlowLayoutNewHorizontalExecutor::~FlowLayoutNewHorizontalExecutor() {
}

Object_ * const FlowLayoutNewHorizontalExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = new UserLayoutManager(new LayoutManager<wxBoxSizer>(new wxBoxSizer(wxHORIZONTAL)));
	return layoutMgr;
}
//---public method
