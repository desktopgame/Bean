#include "TextFieldCanUndoExecutor.h"
#include "../../../env/Boolean.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldCanUndoExecutor::TextFieldCanUndoExecutor() {
}

TextFieldCanUndoExecutor::~TextFieldCanUndoExecutor() {
}

Object_ * const TextFieldCanUndoExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	return Boolean::get(textField->canUndo());
}
//---public method
