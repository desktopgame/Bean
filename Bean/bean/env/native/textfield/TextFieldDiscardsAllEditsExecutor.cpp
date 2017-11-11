#include "TextFieldDiscardsAllEditsExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldDiscardsAllEditsExecutor::TextFieldDiscardsAllEditsExecutor() {
}

TextFieldDiscardsAllEditsExecutor::~TextFieldDiscardsAllEditsExecutor() {
}

Object_ * const TextFieldDiscardsAllEditsExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->discardAllEdits();
	return getNull();
}
//---public method