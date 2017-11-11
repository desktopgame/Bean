#include "SystemGetProperty2Executor.h"
#include "../../user/UserSystem.h"
//public method---
SystemGetProperty2Executor::SystemGetProperty2Executor() {
}

SystemGetProperty2Executor::~SystemGetProperty2Executor() {
}

Object_ * const SystemGetProperty2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* key = arg_cast(String, 0, "String");
	String* val = arg_cast(String, 1, "String");
	UserSystem* uSys = UserSystem::getInstance();
	if (!uSys->contains(*key->getCString())) {
		return val;
	}
	return String::allocString(uSys->str(*key->getCString()));
}
//---public method