#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETFITSIZEEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETFITSIZEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerSetFitSizeExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerSetFitSizeExecutor();
	~LayoutManagerSetFitSizeExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERSETFITSIZEEXECUTOR_H
