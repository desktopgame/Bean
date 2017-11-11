#include "ObjectHashCodeExecutor.h"
#include "../../Numeric.h"

//public method---
ObjectHashCodeExecutor::ObjectHashCodeExecutor() {
}

ObjectHashCodeExecutor::~ObjectHashCodeExecutor() {
}

Object_ * const ObjectHashCodeExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	int i = (int)(unsigned long)invoker;
	return Numeric::newInteger(i);
}
//---public method