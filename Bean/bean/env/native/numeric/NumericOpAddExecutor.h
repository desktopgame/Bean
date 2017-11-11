#pragma once
#ifndef BEAN_NATIVE_NUEMRIC_NUMERICOPADDEXECUTOR_H
#define BEAN_NATIVE_NUEMRIC_NUMERICOPADDEXECUTOR_H
#include "../NativeMethodExecutor.h"
class NumericOpAddExecutor : public NativeMethodExecutor {
public:
	NumericOpAddExecutor();
	~NumericOpAddExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_NUEMRIC_NUMERICOPADDEXECUTOR_H


