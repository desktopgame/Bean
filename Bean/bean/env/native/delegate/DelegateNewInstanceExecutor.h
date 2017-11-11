#pragma once
#ifndef BEAN_ENV_NATIVE_DELEGATE_DELEGATENEWEXECUTOR_H
#define BEAN_ENV_NATIVE_DELEGATE_DELEGATENEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class DelegateNewInstanceExecutor : public TypedNativeMethodExecutor {
public:
	DelegateNewInstanceExecutor();
	~DelegateNewInstanceExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_DELEGATE_DELEGATENEWEXECUTOR_H


