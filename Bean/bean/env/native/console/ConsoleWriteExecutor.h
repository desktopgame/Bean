#pragma once
#ifndef BEAN_ENV_NATIVE_CONSOLE_CONSOLEWRITEEXECUTOR_H
#define BEAN_ENV_NATIVE_CONSOLE_CONSOLEWRITEEXECUTOR_H
#include "../NativeMethodExecutor.h"
class String;
class ConsoleWriteExecutor : public NativeMethodExecutor {
public:
	ConsoleWriteExecutor();
	~ConsoleWriteExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
private:
	void print__(String* str);
};
#endif // !BEAN_ENV_NATIVE_CONSOLE_CONSOLEWRITEEXECUTOR_H


