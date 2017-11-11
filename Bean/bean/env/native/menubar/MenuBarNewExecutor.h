#pragma once
#ifndef BEAN_ENV_NATIVE_MENUBAR_MENUBARNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_MENUBAR_MENUBARNEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuBarNewExecutor : public TypedNativeMethodExecutor {
public:
	MenuBarNewExecutor();
	~MenuBarNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENUBAR_MENUBARNEWEXECUTOR_H
