#pragma once
#ifndef BEAN_ENV_NATIVE_BOOLEAN_BOOLEANTOSTRING_H
#define BEAN_ENV_NATIVE_BOOLEAN_BOOLEANTOSTRING_H
#include "../NativeMethodExecutor.h"
class BooleanToString : public NativeMethodExecutor {
public:
	BooleanToString();
	~BooleanToString();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BOOLEAN_BOOLEANTOSTRING_H