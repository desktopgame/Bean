#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETHEIGHTEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETHEIGHTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentSetHeightExecutor : public TypedNativeMethodExecutor {
public:
	ComponentSetHeightExecutor();
	~ComponentSetHeightExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETHEIGHTEXECUTOR_H
