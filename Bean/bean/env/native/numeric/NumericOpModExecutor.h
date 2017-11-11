#pragma once
#ifndef BEAN_NATIVE_NUMERIC_NUMERICMODEXECUTOR_H
#define BEAN_NATIVE_NUMERIC_NUMERICMODEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class NumericOpModExecutor : public TypedNativeMethodExecutor {
public:
	NumericOpModExecutor();
	~NumericOpModExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_NUMERIC_NUMERICMODEXECUTOR_H


