#pragma once
#ifndef BEAN_ENV_NATIVE_SYSTEM_SYSTEMGETPROPERTY2EXECUTOR_H
#define BEAN_ENV_NATIVE_SYSTEM_SYSTEMGETPROPERTY2EXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class SystemGetProperty2Executor : public TypedNativeMethodExecutor {
public:
	SystemGetProperty2Executor();
	~SystemGetProperty2Executor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_SYSTEM_SYSTEMGETPROPERTY2EXECUTOR_H
