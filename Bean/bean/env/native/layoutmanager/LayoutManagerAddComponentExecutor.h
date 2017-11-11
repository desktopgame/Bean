#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERADDCOMPONENTEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERADDCOMPONENTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerAddComponentExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerAddComponentExecutor();
	~LayoutManagerAddComponentExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERADDCOMPONENTEXECUTOR_H
