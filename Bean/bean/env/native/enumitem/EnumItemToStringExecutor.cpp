#include "EnumItemToStringExecutor.h"
#include "../../String.h"

//public method---
EnumItemToStringExecutor::EnumItemToStringExecutor(std::string name) {
	this->name = name;
}

EnumItemToStringExecutor::~EnumItemToStringExecutor() {
}

Object_ * const EnumItemToStringExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return String::allocString(name);
}
//---public method