#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSBOTTOMEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSBOTTOMEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutParamsBottomExecutor : public TypedNativeMethodExecutor {
public:
	LayoutParamsBottomExecutor();
	~LayoutParamsBottomExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSBOTTOMEXECUTOR_H
