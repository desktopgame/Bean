#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETMAXSIZEEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETMAXSIZEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerGetMaxSizeExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerGetMaxSizeExecutor();
	~LayoutManagerGetMaxSizeExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETMAXSIZEEXECUTOR_H
