#pragma once
#ifndef BEAN_ENV_NATIVE_CONSOLE_CONSOLEREADLINEEXECUTOR_H
#define BEAN_ENV_NATIVE_CONSOLE_CONSOLEREADLINEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ConsoleReadLineExecutor : public TypedNativeMethodExecutor {
public:
	ConsoleReadLineExecutor();
	~ConsoleReadLineExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_CONSOLE_CONSOLEREADLINEEXECUTOR_H
