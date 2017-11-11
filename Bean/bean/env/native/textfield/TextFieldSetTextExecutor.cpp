#include "TextFieldSetTextExecutor.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldSetTextExecutor::TextFieldSetTextExecutor() {
}

TextFieldSetTextExecutor::~TextFieldSetTextExecutor() {
}

Object_ * const TextFieldSetTextExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	String* content = arg_cast(String, 0, "String");
	textField->setText(*content->getCString());
	return getNull();
}
//---public method