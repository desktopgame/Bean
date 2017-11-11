#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETBACKGROUNDEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETBACKGROUNDEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentSetBackgroundExecutor : public TypedNativeMethodExecutor {
public:
	ComponentSetBackgroundExecutor();
	~ComponentSetBackgroundExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETBACKGROUNDEXECUTOR_H
