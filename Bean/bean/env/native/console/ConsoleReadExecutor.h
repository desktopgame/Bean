#pragma once
#ifndef BEAN_ENV_NATIVE_CONSOLE_CONSOLEREADEXECUTOR_H
#define BEAN_ENV_NATIVE_CONSOLE_CONSOLEREADEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ConsoleReadExecutor : public TypedNativeMethodExecutor {
public:
	ConsoleReadExecutor();
	~ConsoleReadExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_CONSOLE_CONSOLEREADEXECUTOR_H
