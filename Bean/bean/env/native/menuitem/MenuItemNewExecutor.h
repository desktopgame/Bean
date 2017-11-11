#pragma once
#ifndef BEAN_ENV_NATIVE_MENUITEM_MENUITEMNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_MENUITEM_MENUITEMNEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuItemNewExecutor : public TypedNativeMethodExecutor {
public:
	MenuItemNewExecutor();
	~MenuItemNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENUITEM_MENUITEMNEWEXECUTOR_H
