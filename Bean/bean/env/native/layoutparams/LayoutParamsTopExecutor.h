#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSTOPEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSTOPEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutParamsTopExecutor : public TypedNativeMethodExecutor {
public:
	LayoutParamsTopExecutor();
	~LayoutParamsTopExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSTOPEXECUTOR_H
