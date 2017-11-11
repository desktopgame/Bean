#include "SystemApplyExecutor.h"
#include "../../user/UserSystem.h"
//public method---
SystemApplyExecutor::SystemApplyExecutor() {
}

SystemApplyExecutor::~SystemApplyExecutor() {
}

Object_ * const SystemApplyExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserSystem* uSys = UserSystem::getInstance();
	uSys->apply(UserSystem::getSysPath());
	return getNull();
}
//---public method