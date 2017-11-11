#include "TextFieldUndoExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldUndoExecutor::TextFieldUndoExecutor() {
}

TextFieldUndoExecutor::~TextFieldUndoExecutor() {
}

Object_ * const TextFieldUndoExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->undo();
	return getNull();
}
//---public method