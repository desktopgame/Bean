#include "LabelNewExecutor.h"
#include "../../../wxgui/Label.h"
#include "../../../env/user/UserFrame.h"
#include "../../../env/user/UserLabel.h"

//public method---
LabelNewExecutor::LabelNewExecutor() {
}

LabelNewExecutor::~LabelNewExecutor() {
}

Object_ * const LabelNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * LabelNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	UserContainer* cont = arg_cast(UserContainer, 0, "Container");
	String* text = arg_cast(String, 1, "String");
	UserLabel* label = new UserLabel(new Label(cont));
	label->setText(*text->getCString());
	return label;
//	return new Reference(label);
}
//---public method
