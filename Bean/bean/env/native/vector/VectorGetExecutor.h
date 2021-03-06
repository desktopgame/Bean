#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORGETSIZEEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORGETSIZEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class VectorGetExecutor : public TypedNativeMethodExecutor {
public:
	VectorGetExecutor();
	~VectorGetExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORGETSIZEEXECUTOR_H
