#pragma once
#ifndef BEAN_ENV_NATIVE_NUMERIC_NUMERICASSHORTEXECUTOR_H
#define BEAN_ENV_NATIVE_NUMERIC_NUMERICASSHORTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericAsShortExecutor : public TypedNativeMethodExecutor {
public:
	NumericAsShortExecutor();
	~NumericAsShortExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_NUMERIC_NUMERICASSHORTEXECUTOR_H
