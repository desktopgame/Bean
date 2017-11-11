#pragma once
#ifndef BEAN_NATIVE_NUMERIC_NUMERICOPDIVEXECUTOR_H
#define BEAN_NATIVE_NUMERIC_NUMERICOPDIVEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericOpDivExecutor : public TypedNativeMethodExecutor {
public:
	NumericOpDivExecutor();
	~NumericOpDivExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_NUMERIC_NUMERICOPDIVEXECUTOR_H


