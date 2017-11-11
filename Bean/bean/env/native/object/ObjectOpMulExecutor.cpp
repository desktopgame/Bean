#include "ObjectOpMulExecutor.h"

//public method---
ObjectOpMulExecutor::ObjectOpMulExecutor() {
}

ObjectOpMulExecutor::~ObjectOpMulExecutor() {
}

Object_ * const ObjectOpMulExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getBoolean(false);
}
//---public method