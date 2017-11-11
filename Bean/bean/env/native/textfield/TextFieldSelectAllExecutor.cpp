#include "TextFieldSelectAllExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldSelectAllExecutor::TextFieldSelectAllExecutor() {
}

TextFieldSelectAllExecutor::~TextFieldSelectAllExecutor() {
}

Object_ * const TextFieldSelectAllExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->selectAll();
	return getNull();
}
//---public method