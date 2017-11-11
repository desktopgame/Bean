#pragma once
#ifndef BEAN_ENV_NATIVE_SYSTEM_SYSTEMAPPLYEXECUTOR_H
#define BEAN_ENV_NATIVE_SYSTEM_SYSTEMAPPLYEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class SystemApplyExecutor : public TypedNativeMethodExecutor {
public:
	SystemApplyExecutor();
	~SystemApplyExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_SYSTEM_SYSTEMAPPLYEXECUTOR_H
