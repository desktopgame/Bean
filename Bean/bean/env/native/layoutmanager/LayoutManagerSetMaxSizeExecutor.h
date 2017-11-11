#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETMAXSIZEEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETMAXSIZEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerSetMaxSizeExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerSetMaxSizeExecutor();
	~LayoutManagerSetMaxSizeExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETMAXSIZEEXECUTOR_H
