#pragma once
#ifndef BEAN_ENV_NATIVE_MATH_MATHMINEXECUTOR_H
#define BEAN_ENV_NATIVE_MATH_MATHMINEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathMinExecutor : public TypedNativeMethodExecutor {
public:
	MathMinExecutor();
	~MathMinExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATH_MATHMINEXECUTOR_H
