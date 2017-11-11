#include "SystemSetPropertyExecutor.h"
#include "../../user/UserSystem.h"
//public method---
SystemSetPropertyExecutor::SystemSetPropertyExecutor() {
}

SystemSetPropertyExecutor::~SystemSetPropertyExecutor() {
}

Object_ * const SystemSetPropertyExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* key = arg_cast(String, 0, "String");
	String* val = arg_cast(String, 1, "String");
	UserSystem* uSys = UserSystem::getInstance();
	uSys->put(*key->getCString(), *val->getCString());
	return getNull();
}
//---public method