#include "ContainerSetLayoutExecutor.h"
#include "../../../env/user/UserContainer.h"
#include "../../../env/user/UserLayoutManager.h"

//public method---
ContainerSetLayoutExecutor::ContainerSetLayoutExecutor() {
}

ContainerSetLayoutExecutor::~ContainerSetLayoutExecutor() {
}

Object_ * const ContainerSetLayoutExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserContainer* cont = static_cast<UserContainer*>(invoker);
	UserLayoutManager* layoutMgr = arg_cast(UserLayoutManager, 0, "LayoutManager");
	cont->setLayout(layoutMgr->getWX());
	return getNull();
}
//---public method