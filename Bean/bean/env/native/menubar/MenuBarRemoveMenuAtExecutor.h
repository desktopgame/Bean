#pragma once
#ifndef BEAN_ENV_NATIVE_MENUBAR_MENUBARREMOVEMENUATEXECUTOR_H
#define BEAN_ENV_NATIVE_MENUBAR_MENUBARREMOVEMENUATEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MenuBarRemoveMenuAtExecutor : public TypedNativeMethodExecutor {
public:
	MenuBarRemoveMenuAtExecutor();
	~MenuBarRemoveMenuAtExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MENUBAR_MENUBARREMOVEMENUATEXECUTOR_H
