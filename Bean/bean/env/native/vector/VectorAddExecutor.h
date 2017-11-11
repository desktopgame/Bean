#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORADDEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORADDEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class VectorAddExecutor : public TypedNativeMethodExecutor {
public:
	VectorAddExecutor();
	~VectorAddExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORADDEXECUTOR_H
