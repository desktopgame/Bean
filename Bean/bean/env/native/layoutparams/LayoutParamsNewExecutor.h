#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSNEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutParamsNewExecutor : public TypedNativeMethodExecutor {
public:
	LayoutParamsNewExecutor();
	~LayoutParamsNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTPARAMS_LAYOUTPARAMSNEWEXECUTOR_H
