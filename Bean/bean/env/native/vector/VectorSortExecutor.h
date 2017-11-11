#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORSORTEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORSORTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
#include "../../Reference.h"
class VectorSortExecutor : public TypedNativeMethodExecutor, public Reference {
public:
	VectorSortExecutor();
	~VectorSortExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORSORTEXECUTOR_H
