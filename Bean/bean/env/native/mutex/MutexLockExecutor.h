#pragma once
#ifndef BEAN_ENV_NATIVE_MUTEX_MUTEXLOCKEXECUTOR_H
#define BEAN_ENV_NATIVE_MUTEX_MUTEXLOCKEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MutexLockExecutor : public TypedNativeMethodExecutor {
public:
	MutexLockExecutor();
	~MutexLockExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MUTEX_MUTEXLOCKEXECUTOR_H
