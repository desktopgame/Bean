#include "PanelNewExecutor.h"
#include "../../../wxgui/Panel.h"
#include "../../../env/user/UserPanel.h"

//public method---
PanelNewExecutor::PanelNewExecutor() {
}

PanelNewExecutor::~PanelNewExecutor() {
}

Object_ * const PanelNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * PanelNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	UserContainer* cont = arg_cast(UserContainer, 0, "Container");
	UserPanel* panel = new UserPanel(new Panel(cont));
	return panel;
}
//---public method
