#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGLASTINDEXOFEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGLASTINDEXOFEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringLastIndexOfExecutor : public TypedNativeMethodExecutor {
public:
	StringLastIndexOfExecutor();
	~StringLastIndexOfExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGLASTINDEXOFEXECUTOR_H
