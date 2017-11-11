#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORPOPEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORPOPEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class VectorPopExecutor : public TypedNativeMethodExecutor {
public:
	VectorPopExecutor();
	~VectorPopExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORPOPEXECUTOR_H
