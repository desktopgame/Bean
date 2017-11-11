#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERDOLAYOUTEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERDOLAYOUTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerDoLayoutExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerDoLayoutExecutor();
	~LayoutManagerDoLayoutExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERDOLAYOUTEXECUTOR_H
