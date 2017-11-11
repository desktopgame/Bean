#include "TextFieldCutExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldCutExecutor::TextFieldCutExecutor() {
}

TextFieldCutExecutor::~TextFieldCutExecutor() {
}

Object_ * const TextFieldCutExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->cut();
	return getNull();
}
//---public method