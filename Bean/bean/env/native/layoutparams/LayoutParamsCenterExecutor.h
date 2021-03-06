#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSCENTEREXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSCENTEREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutParamsCenterExecutor : public TypedNativeMethodExecutor {
public:
	LayoutParamsCenterExecutor();
	~LayoutParamsCenterExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSCENTEREXECUTOR_H
