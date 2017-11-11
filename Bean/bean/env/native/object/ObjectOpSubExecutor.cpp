#include "ObjectOpSubExecutor.h"

//public method---
ObjectOpSubExecutor::ObjectOpSubExecutor() {
}

ObjectOpSubExecutor::~ObjectOpSubExecutor() {
}

Object_ * const ObjectOpSubExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getBoolean(false);
}
//---public method