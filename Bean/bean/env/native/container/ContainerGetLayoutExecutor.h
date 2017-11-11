#pragma once
#ifndef BEAN_ENV_NATIVE_CONTAINER_CONTAINERGETLAYOUTEXECUTOR_H
#define BEAN_ENV_NATIVE_CONTAINER_CONTAINERGETLAYOUTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ContainerGetLayoutExecutor : public TypedNativeMethodExecutor {
public:
	ContainerGetLayoutExecutor();
	~ContainerGetLayoutExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_CONTAINER_CONTAINERGETLAYOUTEXECUTOR_H
