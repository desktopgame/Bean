#pragma once
#ifndef BEAN_ENV_NATIVE_THREAD_THREADGETNAMEEXECUTOR_H
#define BEAN_ENV_NATIVE_THREAD_THREADGETNAMEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ThreadGetNameExecutor : public TypedNativeMethodExecutor {
public:
	ThreadGetNameExecutor();
	~ThreadGetNameExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_THREAD_THREADGETNAMEEXECUTOR_H
