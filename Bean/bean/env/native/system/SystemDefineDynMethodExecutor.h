#pragma once
#ifndef BEAN_ENV_NATIVE_SYSTEM_SYSTEMDEFINEDYNMETHODEXECUTOR_H
#define BEAN_ENV_NATIVE_SYSTEM_SYSTEMDEFINEDYNMETHODEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class SystemDefineDynMethodExecutor : public TypedNativeMethodExecutor {
public:
	SystemDefineDynMethodExecutor();
	~SystemDefineDynMethodExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_SYSTEM_SYSTEMDEFINEDYNMETHODEXECUTOR_H
