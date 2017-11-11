#pragma once
#ifndef BEAN_ENV_NATIVE_ARRAY_ARRAYLENGTHEXECUTOR_H
#define BEAN_ENV_NATIVE_ARRAY_ARRAYLENGTHEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ArrayLengthExecutor : public TypedNativeMethodExecutor {
public:
	ArrayLengthExecutor();
	~ArrayLengthExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_ARRAY_ARRAYLENGTHEXECUTOR_H


