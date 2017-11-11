#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGOPADDEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGOPADDEXECUTOR_H
#include "../NativeMethodExecutor.h"
class StringOpAddExecutor : public NativeMethodExecutor {
public:
	StringOpAddExecutor();
	~StringOpAddExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGOPADDEXECUTOR_H


