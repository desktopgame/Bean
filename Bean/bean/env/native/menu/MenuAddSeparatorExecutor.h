#pragma once
#ifndef BEAN_ENV_NATIVE_MENU_MENUADDSEPARATOREXECUTOR_H
#define BEAN_ENV_NATIVE_MENU_MENUADDSEPARATOREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuAddSeparatorExecutor : public TypedNativeMethodExecutor {
public:
	MenuAddSeparatorExecutor();
	~MenuAddSeparatorExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENU_MENUADDSEPARATOREXECUTOR_H
