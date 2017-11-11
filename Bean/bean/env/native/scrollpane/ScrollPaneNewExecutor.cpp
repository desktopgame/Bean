#include "ScrollPaneNewExecutor.h"
#include "../../../wxgui/ScrollPane.h"
#include "../../../env/user/UserContainer.h"
#include "../../../env/user/UserScrollPane.h"

//public method---
ScrollPaneNewExecutor::ScrollPaneNewExecutor() {
}

ScrollPaneNewExecutor::~ScrollPaneNewExecutor() {
}

Object_ * const ScrollPaneNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * ScrollPaneNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	UserContainer* cont = arg_cast(UserContainer, 0, "Container");
	UserScrollPane* scroll = new UserScrollPane(new ScrollPane(cont));
	return scroll;
}
//---public method