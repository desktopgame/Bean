#pragma once
#ifndef BEAN_ENV_NATIVE_MENU_MENUADDMENUEXECUTOR_H
#define BEAN_ENV_NATIVE_MENU_MENUADDMENUEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuAddMenuExecutor : public TypedNativeMethodExecutor {
public:
	MenuAddMenuExecutor();
	~MenuAddMenuExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENU_MENUADDMENUEXECUTOR_H
