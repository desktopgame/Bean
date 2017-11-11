#include "TextFieldPasteExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldPasteExecutor::TextFieldPasteExecutor() {
}

TextFieldPasteExecutor::~TextFieldPasteExecutor() {
}

Object_ * const TextFieldPasteExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->paste();
	return getNull();
}
//---public method