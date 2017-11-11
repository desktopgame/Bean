#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETWIDTHEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETWIDTHEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentSetWidthExecutor : public TypedNativeMethodExecutor {
public:
	ComponentSetWidthExecutor();
	~ComponentSetWidthExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETWIDTHEXECUTOR_H
