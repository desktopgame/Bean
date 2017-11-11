#pragma once
#ifndef BEAN_ENV_NATIVE_ARRAY_ARRAYGETEXECUTOR_H
#define BEAN_ENV_NATIVE_ARRAY_ARRAYGETEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ArrayGetExecutor : public TypedNativeMethodExecutor {
public:
	ArrayGetExecutor();
	~ArrayGetExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_ARRAY_ARRAYGETEXECUTOR_H


