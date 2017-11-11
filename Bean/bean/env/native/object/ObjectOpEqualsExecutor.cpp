#include "ObjectOpEqualsExecutor.h"
#include "../../Boolean.h"

//public method---
ObjectOpEqualsExecutor::ObjectOpEqualsExecutor() {
}

ObjectOpEqualsExecutor::~ObjectOpEqualsExecutor() {
}

Object_ * const ObjectOpEqualsExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return Boolean::get(invoker == args.at(0));
}
//---public method