#pragma once
#ifndef BEAN_ENV_NATIVE_MATH_MATHCOSEXECUTOR_H
#define BEAN_ENV_NATIVE_MATH_MATHCOSEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathCosExecutor : public TypedNativeMethodExecutor {
public:
	MathCosExecutor();
	~MathCosExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATH_MATHCOSEXECUTOR_H