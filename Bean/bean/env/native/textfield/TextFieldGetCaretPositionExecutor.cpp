#include "TextFieldGetCaretPositionExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserTextField.h"


//public method---
TextFieldGetCaretPositionExecutor::TextFieldGetCaretPositionExecutor() {
}

TextFieldGetCaretPositionExecutor::~TextFieldGetCaretPositionExecutor() {
}

Object_ * const TextFieldGetCaretPositionExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	int offset = textField->getCaretPosition();
	return Numeric::newInteger(offset);
}
//---public method
