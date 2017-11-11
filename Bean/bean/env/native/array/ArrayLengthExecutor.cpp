#include "ArrayLengthExecutor.h"
#include "../../../env/user/UserArray.h"

//public method---
ArrayLengthExecutor::ArrayLengthExecutor() {
}

ArrayLengthExecutor::~ArrayLengthExecutor() {
}

Object_ * const ArrayLengthExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserArray* arr = invoker->asUserArray();
	return getInteger(arr->getLength());
}
//---public method