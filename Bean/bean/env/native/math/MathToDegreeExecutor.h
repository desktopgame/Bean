#pragma once
#ifndef BEAN_ENV_NATIVE_MATH_MATHTODEGREEEXECUTOR_H
#define BEAN_ENV_NATIVE_MATH_MATHTODEGREEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathToDegreeExecutor : public TypedNativeMethodExecutor {
public:
	MathToDegreeExecutor();
	~MathToDegreeExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATH_MATHTODEGREEEXECUTOR_H
