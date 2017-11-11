#include "TextFieldSetCaretPositionExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldSetCaretPositionExecutor::TextFieldSetCaretPositionExecutor() {
}

TextFieldSetCaretPositionExecutor::~TextFieldSetCaretPositionExecutor() {
}

Object_ * const TextFieldSetCaretPositionExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	Numeric* offset = arg_cast(Numeric, 0, "Numeric");
	int max = textField->getText().size() - 1;
	/*
	//値が 0 以下
	//値が テキスト全体の長さを超えている
	if (throw_if_overrange(
		offset,
		0,
		max,
		message_overrange(offset, 0, max)
	)) {
		return getNull();
	}
	*/
	textField->setCaretPosition(offset->getCInt());
	return getNull();
}
//---public method
