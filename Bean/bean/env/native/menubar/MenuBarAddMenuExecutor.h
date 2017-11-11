#pragma once
#ifndef BEAN_ENV_NATIVE_MENUBAR_MENUBARADDMENUEXECUTOR_H
#define BEAN_ENV_NATIVE_MENUBAR_MENUBARADDMENUEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuBarAddMenuExecutor : public TypedNativeMethodExecutor {
public:
	MenuBarAddMenuExecutor();
	~MenuBarAddMenuExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENUBAR_MENUBARADDMENUEXECUTOR_H
