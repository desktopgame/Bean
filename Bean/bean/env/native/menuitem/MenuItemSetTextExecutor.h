#pragma once
#ifndef BEAN_ENV_NATIVE_MENUITEM_MENUITEMSETTEXTEXECUTOR_H
#define BEAN_ENV_NATIVE_MENUITEM_MENUITEMSETTEXTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuItemSetTextExecutor : public TypedNativeMethodExecutor {
public:
	MenuItemSetTextExecutor();
	~MenuItemSetTextExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENUITEM_MENUITEMSETTEXTEXECUTOR_H
