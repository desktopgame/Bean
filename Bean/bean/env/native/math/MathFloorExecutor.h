#pragma once
#ifndef BEAN_ENV_NATIVE_MATH_MATHFLOOREXECUTOR_H
#define BEAN_ENV_NATIVE_MATH_MATHFLOOREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MathFloorExecutor : public TypedNativeMethodExecutor {
public:
	MathFloorExecutor();
	~MathFloorExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATH_MATHFLOOREXECUTOR_H
