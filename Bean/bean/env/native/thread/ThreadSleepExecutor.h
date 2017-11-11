#pragma once
#ifndef BEAN_ENV_NATIVE_THREAD_THREADSLEEPEXECUTOR_H
#define BEAN_ENV_NATIVE_THREAD_THREADSLEEPEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ThreadSleepExecutor : public TypedNativeMethodExecutor {
public:
	ThreadSleepExecutor();
	~ThreadSleepExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_THREAD_THREADSLEEPEXECUTOR_H
