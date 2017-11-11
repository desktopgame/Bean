#include "NumericAsCharacterExecutor.h"
#include "../../Character.h"
#include "../../Numeric.h"

//public method---
NumericAsCharacterExecutor::NumericAsCharacterExecutor() {
}

NumericAsCharacterExecutor::~NumericAsCharacterExecutor() {
}

Object_ * const NumericAsCharacterExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Numeric* self = arg_cast(Numeric, 0, "Numeric");
	int i = self->getCInt();
	return new Character(static_cast<char>(i));
}
//---public method
