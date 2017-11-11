#pragma once
#ifndef BEAN_ENV_NATIVE_NUMERIC_NUMERICASLONGEXECUTOR_H
#define BEAN_ENV_NATIVE_NUMERIC_NUMERICASLONGEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericAsLongExecutor : public TypedNativeMethodExecutor {
public:
	NumericAsLongExecutor();
	~NumericAsLongExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_NUMERIC_NUMERICASLONGEXECUTOR_H
