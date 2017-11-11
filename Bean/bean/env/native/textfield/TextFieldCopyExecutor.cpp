#include "TextFieldCopyExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldCopyExecutor::TextFieldCopyExecutor() {
}

TextFieldCopyExecutor::~TextFieldCopyExecutor() {
}

Object_ * const TextFieldCopyExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->copy();
	return getNull();
}
//---public method