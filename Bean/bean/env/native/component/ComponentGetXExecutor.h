#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETXEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETXEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentGetXExecutor : public TypedNativeMethodExecutor {
public:
	ComponentGetXExecutor();
	~ComponentGetXExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETXEXECUTOR_H
