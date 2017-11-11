#pragma once
#ifndef BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETCOMPONENTCOUNTEXECUTOR_H
#define BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETCOMPONENTCOUNTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LayoutManagerGetComponentCountExecutor : public TypedNativeMethodExecutor {
public:
	LayoutManagerGetComponentCountExecutor();
	~LayoutManagerGetComponentCountExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LAYOUTMANAGER_LAYOUTMANAGERGETCOMPONENTCOUNTEXECUTOR_H
