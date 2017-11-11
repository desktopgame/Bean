#pragma once
#ifndef BEAN_ENV_NATIVE_THREAD_THREADSTARTEXECUTOR_H
#define BEAN_ENV_NATIVE_THREAD_THREADSTARTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ThreadStartExecutor : public TypedNativeMethodExecutor {
public:
	ThreadStartExecutor();
	~ThreadStartExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_THREAD_THREADSTARTEXECUTOR_H
