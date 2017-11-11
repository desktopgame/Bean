#include "TextFieldNewExecutor.h"
#include "../../../wxgui/TextField.h"
#include "../../../env/user/UserContainer.h"
#include "../../../env/user/UserTextField.h"

//public method---
TextFieldNewExecutor::TextFieldNewExecutor() {
}

TextFieldNewExecutor::~TextFieldNewExecutor() {
}

Object_ * const TextFieldNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * TextFieldNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	UserContainer* parent = arg_cast(UserContainer, 0, "Container");
	UserTextField* textField = new UserTextField(new TextField(parent));
	return textField;
}
//---public method
