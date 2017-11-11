#pragma once
#ifndef BEAN_ENV_NATIVE_DELEGATE_DELEGATECALLEXECUTOR_H
#define BEAN_ENV_NATIVE_DELEGATE_DELEGATECALLEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class DelegateCallExecutor : public TypedNativeMethodExecutor {
public:
	DelegateCallExecutor();
	~DelegateCallExecutor();
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_DELEGATE_DELEGATECALLEXECUTOR_H


