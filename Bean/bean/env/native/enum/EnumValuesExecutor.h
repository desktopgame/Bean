#pragma once
#ifndef BEAN_ENV_NATIVE_ENUM_ENUMVALUESEXECUTOR_H
#define BEAN_ENV_NATIVE_ENUM_ENUMVALUESEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class EnumValuesExecutor : public TypedNativeMethodExecutor {
public:
	EnumValuesExecutor();
	~EnumValuesExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_ENUM_ENUMVALUESEXECUTOR_H
