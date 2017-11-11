#pragma once
#ifndef BEAN_ENV_NATIVE_MATHMAXEXECUTOR_H
#define BEAN_ENV_NATIVE_MATHMAXEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathMaxExecutor : public TypedNativeMethodExecutor {
public:
	MathMaxExecutor();
	~MathMaxExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATHMAXEXECUTOR_H
