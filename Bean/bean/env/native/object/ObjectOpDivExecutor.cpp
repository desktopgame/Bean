#include "ObjectOpDivExecutor.h"
#include "../../Null.h"

//public method---
ObjectOpDivExecutor::ObjectOpDivExecutor() {
}

ObjectOpDivExecutor::~ObjectOpDivExecutor() {
}

Object_ * const ObjectOpDivExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return Null::getInstance();
}
//---public method