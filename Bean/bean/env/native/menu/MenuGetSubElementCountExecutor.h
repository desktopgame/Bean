#pragma once
#ifndef BEAN_ENV_NATIVE_MENU_MENUGETSUBELEMENTCOUNTEXECUTOR_H
#define BEAN_ENV_NATIVE_MENU_MENUGETSUBELEMENTCOUNTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuGetSubElementCountExecutor : public TypedNativeMethodExecutor {
public:
	MenuGetSubElementCountExecutor();
	~MenuGetSubElementCountExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENU_MENUGETSUBELEMENTCOUNTEXECUTOR_H
