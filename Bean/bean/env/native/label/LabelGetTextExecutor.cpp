#include "LabelGetTextExecutor.h"
#include "../../../env/user/UserLabel.h"

//public method---
LabelGetTextExecutor::LabelGetTextExecutor() {
}

LabelGetTextExecutor::~LabelGetTextExecutor() {
}

Object_ * const LabelGetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserLabel* label = static_cast<UserLabel*>(invoker);
	return String::allocString(label->getText());
}
//---public method