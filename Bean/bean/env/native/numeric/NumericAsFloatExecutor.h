#pragma once
#ifndef BEAN_ENV_NATIVE_NUMERIC_NUMERICASFLOATEXECUTOR_H
#define BEAN_ENV_NATIVE_NUMERIC_NUMERICASFLOATEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericAsFloatExecutor : public TypedNativeMethodExecutor {
public:
	NumericAsFloatExecutor();
	~NumericAsFloatExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_NUMERIC_NUMERICASFLOATEXECUTOR_H
