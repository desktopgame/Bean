#include "SystemGetPropertyExecutor.h"
#include "../../user/UserSystem.h"
//public method---
SystemGetPropertyExecutor::SystemGetPropertyExecutor() {
}

SystemGetPropertyExecutor::~SystemGetPropertyExecutor() {
}

Object_ * const SystemGetPropertyExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* key = arg_cast(String, 0, "String");
	UserSystem* uSys = UserSystem::getInstance();
	if (!uSys->contains(*key->getCString())) {
		return getNull();
	}
	return String::allocString(uSys->str(*key->getCString()));
}
//---public method