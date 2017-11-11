#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGLASTINDEXOF2EXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGLASTINDEXOF2EXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringLastIndexOf2Executor : public TypedNativeMethodExecutor {
public:
	StringLastIndexOf2Executor();
	~StringLastIndexOf2Executor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGLASTINDEXOF2EXECUTOR_H
