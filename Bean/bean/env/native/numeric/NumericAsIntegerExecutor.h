#pragma once
#ifndef BEAN_ENV_NATIVE_NUMERIC_NUMERICASINTEGEREXECUTOR_H
#define BEAN_ENV_NATIVE_NUMERIC_NUMERICASINTEGEREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericAsIntegerExecutor : public TypedNativeMethodExecutor {
public:
	NumericAsIntegerExecutor();
	~NumericAsIntegerExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_NUMERIC_NUMERICASINTEGEREXECUTOR_H
