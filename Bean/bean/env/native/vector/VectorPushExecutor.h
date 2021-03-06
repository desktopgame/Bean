#pragma once
#ifndef BEAN_ENV_NATIVE_VECTOR_VECTORPUSHEXECUTOR_H
#define BEAN_ENV_NATIVE_VECTOR_VECTORPUSHEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class VectorPushExecutor : public TypedNativeMethodExecutor {
public:
	VectorPushExecutor();
	~VectorPushExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_VECTOR_VECTORPUSHEXECUTOR_H
