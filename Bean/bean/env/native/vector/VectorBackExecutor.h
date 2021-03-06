#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORBACKEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORBACKEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class VectorBackExecutor : public TypedNativeMethodExecutor {
public:
	VectorBackExecutor();
	~VectorBackExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORBACKEXECUTOR_H
