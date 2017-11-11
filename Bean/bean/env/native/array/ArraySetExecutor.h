#pragma once
#ifndef BEAN_ENV_NATIVE_ARRAY_ARRAYSETEXECUTOR_H
#define BEAN_ENV_NATIVE_ARRAY_ARRAYSETEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ArraySetExecutor : public TypedNativeMethodExecutor {
public:
	ArraySetExecutor();
	~ArraySetExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_ARRAY_ARRAYSETEXECUTOR_H


