#pragma once
#ifndef BEAN_ENV_NATIVE_CHECKBOX_CHECKBOXMENUITEMSETSELECTEDEXECUTOR_H
#define BEAN_ENV_NATIVE_CHECKBOX_CHECKBOXMENUITEMSETSELECTEDEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class CheckBoxMenuItemSetSelectedExecutor : public TypedNativeMethodExecutor {
public:
	CheckBoxMenuItemSetSelectedExecutor();
	~CheckBoxMenuItemSetSelectedExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_CHECKBOX_CHECKBOXMENUITEMSETSELECTEDEXECUTOR_H
