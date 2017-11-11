#pragma once
#ifndef BEAN_ENV_NATIVE_NUMERIC_NUMERICASDOUBLEEXECUTOR_H
#define BEAN_ENV_NATIVE_NUMERIC_NUMERICASDOUBLEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericAsDoubleExecutor : public TypedNativeMethodExecutor {
public:
	NumericAsDoubleExecutor();
	~NumericAsDoubleExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_NUMERIC_NUMERICASDOUBLEEXECUTOR_H
