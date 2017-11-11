#pragma once
#ifndef BEAN_ENV_NATIVE_CONTAINER_CONTAINERSETLAYOUTEXECUTOR_H
#define BEAN_ENV_NATIVE_CONTAINER_CONTAINERSETLAYOUTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ContainerSetLayoutExecutor : public TypedNativeMethodExecutor {
public:
	ContainerSetLayoutExecutor();
	~ContainerSetLayoutExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_CONTAINER_CONTAINERSETLAYOUTEXECUTOR_H
