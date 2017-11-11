#include "LabelSetTextExecutor.h"
#include "../../../env/user/UserLabel.h"

//public method---
LabelSetTextExecutor::LabelSetTextExecutor() {
}

LabelSetTextExecutor::~LabelSetTextExecutor() {
}

Object_ * const LabelSetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLabel* label = static_cast<UserLabel*>(invoker);
	String* text = arg_cast(String, 0, "String");
	label->setText(*text->getCString());
	return getNull();
}
//---public method