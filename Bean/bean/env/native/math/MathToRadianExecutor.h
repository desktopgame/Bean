#pragma once
#ifndef BEAN_ENV_NATIVE_MATH_MATHTORADIANEEXECUTOR_H
#define BEAN_ENV_NATIVE_MATH_MATHTORADIANEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathToRadianExecutor : public TypedNativeMethodExecutor {
public:
	MathToRadianExecutor();
	~MathToRadianExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATH_MATHTORADIANEEXECUTOR_H