#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETMINSIZEEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETMINSIZEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerSetMinSizeExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerSetMinSizeExecutor();
	~LayoutManagerSetMinSizeExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETMINSIZEEXECUTOR_H
