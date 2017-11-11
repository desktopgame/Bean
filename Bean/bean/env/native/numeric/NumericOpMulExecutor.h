#pragma once
#ifndef BEAN_NATIVE_NUMERIC_NUMERICOPMULEXECUTOR_H
#define BEAN_NATIVE_NUMERIC_NUMERICOPMULEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericOpMulExecutor : public TypedNativeMethodExecutor {
public:
	NumericOpMulExecutor();
	~NumericOpMulExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_NUMERIC_NUMERICOPMULEXECUTOR_H


