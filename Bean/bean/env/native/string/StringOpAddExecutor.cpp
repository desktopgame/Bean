#include "StringOpAddExecutor.h"
#include "../../Object_.h"
#include "../../String.h"

//public method---
StringOpAddExecutor::StringOpAddExecutor() {
}

StringOpAddExecutor::~StringOpAddExecutor() {
}

Object_ * const StringOpAddExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return invoker->add(args.at(0));
}
//---public method
