#pragma once
#ifndef BEAN_ENV_NATIVE_SYSTEM_SYSTEMDEFINEDYNFIELDEXECUTOR_H
#define BEAN_ENV_NATIVE_SYSTEM_SYSTEMDEFINEDYNFIELDEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class SystemDefineDynFieldExecutor : public TypedNativeMethodExecutor {
public:
	SystemDefineDynFieldExecutor();
	~SystemDefineDynFieldExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_SYSTEM_SYSTEMDEFINEDYNFIELDEXECUTOR_H
