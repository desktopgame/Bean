#pragma once
#ifndef BEAN_ENV_NATIVE_MUTEX_MUTEXUNLOCKEXECUTOR_H
#define BEAN_ENV_NATIVE_MUTEX_MUTEXUNLOCKEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MutexUnlockExecutor : public TypedNativeMethodExecutor {
public:
	MutexUnlockExecutor();
	~MutexUnlockExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MUTEX_MUTEXUNLOCKEXECUTOR_H
