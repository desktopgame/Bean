#pragma once
#ifndef BEAN_NATIVE_NUMERIC_NUMERICOPEQUALSEXECUTOR_H
#define BEAN_NATIVE_NUMERIC_NUMERICOPEQUALSEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericOpEqualsExecutor : public TypedNativeMethodExecutor {
public:
	NumericOpEqualsExecutor();
	~NumericOpEqualsExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_NUMERIC_NUMERICOPEQUALSEXECUTOR_H


