#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETFITSIZEEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETFITSIZEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerGetFitSizeExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerGetFitSizeExecutor();
	~LayoutManagerGetFitSizeExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETFITSIZEEXECUTOR_H
