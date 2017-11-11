#include "SystemDefineDynMethodExecutor.h"
#include "../../user/UserDelegate.h"
//public method---
SystemDefineDynMethodExecutor::SystemDefineDynMethodExecutor() {
}

SystemDefineDynMethodExecutor::~SystemDefineDynMethodExecutor() {
}

Object_ * const SystemDefineDynMethodExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* inst = args.at(0);
	String* name = arg_cast(String, 1, "String");
	UserDelegate* ud = arg_cast(UserDelegate, 2, "Delegate");
	std::string cName = *name->getCString();
	inst->defineDynMethod(*name->getCString(), ud);
	return getNull();
}
//---public method