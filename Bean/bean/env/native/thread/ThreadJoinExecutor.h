#pragma once
#ifndef BEAN_ENV_NATIVE_THREAD_THREADJOINEXECUTOR_H
#define BEAN_ENV_NATIVE_THREAD_THREADJOINEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ThreadJoinExecutor : public TypedNativeMethodExecutor {
public:
	ThreadJoinExecutor();
	~ThreadJoinExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_THREAD_THREADJOINEXECUTOR_H
