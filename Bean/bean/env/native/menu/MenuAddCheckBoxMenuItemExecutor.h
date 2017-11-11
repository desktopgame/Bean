#pragma once
#ifndef BEAN_ENV_NATIVE_MENU_MENUADDCHECKBOXMENUITEMEXECUTOR_H
#define BEAN_ENV_NATIVE_MENU_MENUADDCHECKBOXMENUITEMEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuAddCheckBoxMenuItemExecutor : public TypedNativeMethodExecutor {
public:
	MenuAddCheckBoxMenuItemExecutor();
	~MenuAddCheckBoxMenuItemExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENU_MENUADDCHECKBOXMENUITEMEXECUTOR_H
