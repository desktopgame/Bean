#pragma once
#ifndef BEAN_ENV_NATIVE_NUMERIC_NUMERICTOSTRINGEXECUTOR_H
#define BEAN_ENV_NATIVE_NUMERIC_NUMERICTOSTRINGEXECUTOR_H
#include "../NativeMethodExecutor.h"
#include "../../Numeric.h"
#include "../../String.h"
class NumericToStringExecutor : public NativeMethodExecutor {
public:
	NumericToStringExecutor();
	~NumericToStringExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_NUMERIC_NUMERICTOSTRINGEXECUTOR_H


