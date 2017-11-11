#include "TextFieldInsertExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldInsertExecutor::TextFieldInsertExecutor() {
}

TextFieldInsertExecutor::~TextFieldInsertExecutor() {
}

Object_ * const TextFieldInsertExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	Numeric* offset = arg_cast(Numeric, 0, "Numeric");
	String* content = arg_cast(String, 1, "String");
	Numeric* length = getInteger(content->getCString()->size())->asNumeric();
	textField->insert(*content->getCString(), offset->getCInt());
	return getNull();
}
//---public method
