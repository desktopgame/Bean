#pragma once
#ifndef BEAN_ENV_NATIVE_MENUITEM_MENUITEMGETTEXTEXECUTOR_H
#define BEAN_ENV_NATIVE_MENUITEM_MENUITEMGETTEXTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuItemGetTextExecutor : public TypedNativeMethodExecutor {
public:
	MenuItemGetTextExecutor();
	~MenuItemGetTextExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENUITEM_MENUITEMGETTEXTEXECUTOR_H
