#pragma once
#ifndef BEAN_ENV_NATIVE_CONSOLE_CONSOLEWRITELINEEXECUTOR_H
#define BEAN_ENV_NATIVE_CONSOLE_CONSOLEWRITELINEEXECUTOR_H
#include "../NativeMethodExecutor.h"
class String;
class ConsoleWriteLineExecutor : public NativeMethodExecutor {
public:
	ConsoleWriteLineExecutor();
	~ConsoleWriteLineExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
private:
	void println__(String* str);
};
#endif // !BEAN_ENV_NATIVE_CONSOLE_CONSOLEWRITELINEEXECUTOR_H


