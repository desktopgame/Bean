#include "ObjectToStringExecutor.h"

//public method---
ObjectToStringExecutor::ObjectToStringExecutor() {
}

ObjectToStringExecutor::~ObjectToStringExecutor() {
}

Object_ * const ObjectToStringExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	std::string name = invoker->getClass()->getName();
	return String::allocString(name);
}
//---public method