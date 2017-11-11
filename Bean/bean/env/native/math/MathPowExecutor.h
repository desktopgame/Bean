#pragma once
#ifndef BEAN_ENV_NATIVE_MATHPOWEXECUTOR_H
#define BEAN_ENV_NATIVE_MATHPOWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathPowExecutor : public TypedNativeMethodExecutor {
public:
	MathPowExecutor();
	~MathPowExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATHPOWEXECUTOR_H
