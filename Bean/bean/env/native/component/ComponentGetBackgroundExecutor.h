#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETBACKGROUNDEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETBACKGROUNDEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentGetBackgroundExecutor : public TypedNativeMethodExecutor {
public:
	ComponentGetBackgroundExecutor();
	~ComponentGetBackgroundExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTGETBACKGROUNDEXECUTOR_H
