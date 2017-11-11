#include "ObjectOpModExecutor.h"

//public method---
ObjectOpModExecutor::ObjectOpModExecutor() {
}

ObjectOpModExecutor::~ObjectOpModExecutor() {
}

Object_ * const ObjectOpModExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getBoolean(false);
}
//---public method