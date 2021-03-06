#pragma once
#ifndef BEAN_ENV_NATIVE_MENU_MENUREMOVESUBELEMENTATEXECUTOR_H
#define BEAN_ENV_NATIVE_MENU_MENUREMOVESUBELEMENTATEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuRemoveSubElementAtExecutor : public TypedNativeMethodExecutor {
public:
	MenuRemoveSubElementAtExecutor();
	~MenuRemoveSubElementAtExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENU_MENUREMOVESUBELEMENTATEXECUTOR_H
