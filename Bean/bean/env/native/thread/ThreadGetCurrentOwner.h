#pragma once
#ifndef BEAN_ENV_NATIVE_THREAD_THREADGETCURRENTOWNER_H
#define BEAN_ENV_NATIVE_THREAD_THREADGETCURRENTOWNER_H
#include "../TypedNativeMethodExecutor.h"
class ThreadGetCurrentOwner : public TypedNativeMethodExecutor {
public:
	ThreadGetCurrentOwner();
	~ThreadGetCurrentOwner();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_THREAD_THREADGETCURRENTOWNER_H
