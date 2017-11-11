#pragma once
#ifndef BEAN_ENV_NATIVE_THREAD_THREADNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_THREAD_THREADNEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ThreadNewExecutor : public TypedNativeMethodExecutor {
public:
	ThreadNewExecutor();
	~ThreadNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_THREAD_THREADNEWEXECUTOR_H
