#include "TextFieldGetTextExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldGetTextExecutor::TextFieldGetTextExecutor() {
}

TextFieldGetTextExecutor::~TextFieldGetTextExecutor() {
}

Object_ * const TextFieldGetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	String* ret = String::allocString(textField->getText());
	return ret;
}
//---public method