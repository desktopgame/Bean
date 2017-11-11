#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGREMOVEEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGREMOVEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringRemoveExecutor : public TypedNativeMethodExecutor {
public:
	StringRemoveExecutor();
	~StringRemoveExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGREMOVEEXECUTOR_H
