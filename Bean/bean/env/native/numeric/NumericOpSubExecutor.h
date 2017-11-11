#pragma once
#ifndef BEAN_NATIVE_NUMERIC_NUMERICOPSUBEXECUTOR_H
#define BEAN_NATIVE_NUMERIC_NUMERICOPSUBEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericOpSubExecutor : public TypedNativeMethodExecutor {
public:
	NumericOpSubExecutor();
	~NumericOpSubExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_NUMERIC_NUMERICOPSUBEXECUTOR_H


