#include "SystemDefineDynFieldExecutor.h"
//public method---
SystemDefineDynFieldExecutor::SystemDefineDynFieldExecutor() {
}

SystemDefineDynFieldExecutor::~SystemDefineDynFieldExecutor() {
}

Object_ * const SystemDefineDynFieldExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* inst = args.at(0);
	String* name = arg_cast(String, 1, "String");
	Object_* val = args.at(2);
	std::string cName = *name->getCString();
	inst->defineDynField(cName, val);
	return getNull();
}
//---public method