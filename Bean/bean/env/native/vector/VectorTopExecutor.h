#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORTOPEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORTOPEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class VectorTopExecutor : public TypedNativeMethodExecutor {
public:
	VectorTopExecutor();
	~VectorTopExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORTOPEXECUTOR_H
