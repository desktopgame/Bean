#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGTOSTRINGEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGTOSTRINGEXECUTOR_H
#include "../NativeMethodExecutor.h"
class StringToStringExecutor : public NativeMethodExecutor {
public:
	StringToStringExecutor();
	~StringToStringExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGTOSTRINGEXECUTOR_H


