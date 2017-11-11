#pragma once
#ifndef BEAN_ENV_NATIVE_MATH_MATHSINEXECUTOR_H
#define BEAN_ENV_NATIVE_MATH_MATHSINEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathSinExecutor : public TypedNativeMethodExecutor {
public:
	MathSinExecutor();
	~MathSinExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATH_MATHSINEXECUTOR_H
