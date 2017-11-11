#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETYEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETYEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentGetYExecutor : public TypedNativeMethodExecutor {
public:
	ComponentGetYExecutor();
	~ComponentGetYExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETYEXECUTOR_H
