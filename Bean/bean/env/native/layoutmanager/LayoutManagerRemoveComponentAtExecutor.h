#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERREMOVECOMPONENTATEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERREMOVECOMPONENTATEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerRemoveComponentAtExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerRemoveComponentAtExecutor();
	~LayoutManagerRemoveComponentAtExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERREMOVECOMPONENTATEXECUTOR_H
