#pragma once
#ifndef BEAN_ENV_NATIVE_NUMERIC_NUMERICASCHARACTEREXECUTOR_H
#define BEAN_ENV_NATIVE_NUMERIC_NUMERICASCHARACTEREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericAsCharacterExecutor : public TypedNativeMethodExecutor {
public:
	NumericAsCharacterExecutor();
	~NumericAsCharacterExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_NUMERIC_NUMERICASCHARACTEREXECUTOR_H
