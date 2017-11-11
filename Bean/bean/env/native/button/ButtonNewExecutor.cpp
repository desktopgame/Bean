#include "ButtonNewExecutor.h"
#include "../../../wxgui/Button.h"
#include "../../../wxgui/FrameInterface.h"
#include "../../../env/user/UserButton.h"
#include "../../../env/user/UserFrame.h"

//public method---
ButtonNewExecutor::ButtonNewExecutor() {
}

ButtonNewExecutor::~ButtonNewExecutor() {
}

Object_ * const ButtonNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * ButtonNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	UserContainer* cont = arg_cast(UserContainer, 0, "Container");
	String* label = arg_cast(String, 1, "String");
	UserButton* button = new UserButton(new Button(cont));
	button->setText(*label->getCString());
	return button;
}
//---public method
