#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETFITSIZEEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETFITSIZEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentSetFitSizeExecutor : public TypedNativeMethodExecutor {
public:
	ComponentSetFitSizeExecutor();
	~ComponentSetFitSizeExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTSETFITSIZEEXECUTOR_H
