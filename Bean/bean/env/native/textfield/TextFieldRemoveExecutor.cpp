#include "TextFieldRemoveExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldRemoveExecutor::TextFieldRemoveExecutor() {
}

TextFieldRemoveExecutor::~TextFieldRemoveExecutor() {
}

Object_ * const TextFieldRemoveExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	Numeric* offset = arg_cast(Numeric, 0, "Numeric");
	Numeric* length = arg_cast(Numeric, 1, "Numeric");
	textField->remove(offset->getCInt(), length->getCInt());
	return getNull();
}
//---public method
