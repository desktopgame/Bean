#include "FlowLayoutNewVerticalExecutor.h"
#include "../../../wxgui/LayoutManager.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
FlowLayoutNewVerticalExecutor::FlowLayoutNewVerticalExecutor() {
}

FlowLayoutNewVerticalExecutor::~FlowLayoutNewVerticalExecutor() {
}

Object_ * const FlowLayoutNewVerticalExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLayoutManager* layoutMgr = new UserLayoutManager(new LayoutManager<wxBoxSizer>(new wxBoxSizer(wxVERTICAL)));
	return layoutMgr;
}
//---public method
