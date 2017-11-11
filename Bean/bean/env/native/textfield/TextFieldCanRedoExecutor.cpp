#include "TextFieldCanRedoExecutor.h"
#include "../../../env/Boolean.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldCanRedoExecutor::TextFieldCanRedoExecutor() {
}

TextFieldCanRedoExecutor::~TextFieldCanRedoExecutor() {
}

Object_ * const TextFieldCanRedoExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	return Boolean::get(textField->canRedo());
}
//---public method
