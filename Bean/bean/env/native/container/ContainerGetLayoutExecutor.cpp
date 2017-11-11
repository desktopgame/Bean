#include "ContainerGetLayoutExecutor.h"
#include "../../../wxgui/LayoutManager.h"
#include "../../../env/user/UserContainer.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
ContainerGetLayoutExecutor::ContainerGetLayoutExecutor() {
}

ContainerGetLayoutExecutor::~ContainerGetLayoutExecutor() {
}

Object_ * const ContainerGetLayoutExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserContainer* cont = static_cast<UserContainer*>(invoker);
	wxSizer* sizer = cont->getLayout();
	return new UserLayoutManager(new LayoutManager<wxSizer>(sizer));
}
//---public method