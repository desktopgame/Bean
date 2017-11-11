#include "TextFieldRedoExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldRedoExecutor::TextFieldRedoExecutor() {
}

TextFieldRedoExecutor::~TextFieldRedoExecutor() {
}

Object_ * const TextFieldRedoExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->redo();
	return getNull();
}
//---public method