#pragma once
#ifndef BEAN_ENV_NATIVE_MATH_MATHCEILEXECUTOR_H
#define BEAN_ENV_NATIVE_MATH_MATHCEILEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathCeilExecutor : public TypedNativeMethodExecutor {
public:
	MathCeilExecutor();
	~MathCeilExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATH_MATHCEILEXECUTOR_H
