#pragma once
#ifndef BEAN_ENV_NATIVE_COMPONENT_COMPONENTREPAINTEXECUTOR_H
#define BEAN_ENV_NATIVE_COMPONENT_COMPONENTREPAINTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ComponentRepaintExecutor : public TypedNativeMethodExecutor {
public:
	ComponentRepaintExecutor();
	~ComponentRepaintExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COMPONENT_COMPONENTREPAINTEXECUTOR_H
