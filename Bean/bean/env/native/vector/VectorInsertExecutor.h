#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORINSERTEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORINSERTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class VectorInsertExecutor : public TypedNativeMethodExecutor {
public:
	VectorInsertExecutor();
	~VectorInsertExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORINSERTEXECUTOR_H
