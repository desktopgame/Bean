#pragma once
#ifndef BEAN_ENV_NATIVE_MUTEX_MUTEXNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_MUTEX_MUTEXNEWEXECUTOR_H
#include "../NativeMethodExecutor.h"
class MutexNewExecutor : public NativeMethodExecutor {
public:
	MutexNewExecutor();
	~MutexNewExecutor();

	// NativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	virtual Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MUTEX_MUTEXNEWEXECUTOR_H
