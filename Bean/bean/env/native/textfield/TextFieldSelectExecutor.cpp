#include "TextFieldSelectExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldSelectExecutor::TextFieldSelectExecutor() {
}

TextFieldSelectExecutor::~TextFieldSelectExecutor() {
}

Object_ * const TextFieldSelectExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* start = arg_cast(Numeric, 0, "Numeric");
	Numeric* end = arg_cast(Numeric, 1, "Numeric");
	UserTextField* textField = static_cast<UserTextField*>(invoker);
	textField->select(start->getCInt(), end->getCInt());
	return getNull();
}
//---public method
