#pragma once
#ifndef BEAN_ENV_NATIVE_SCROLLPANE_SCROLLPANENEWEXECUTOR_H
#define BEAN_ENV_NATIVE_SCROLLPANE_SCROLLPANENEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ScrollPaneNewExecutor : public TypedNativeMethodExecutor {
public:
	ScrollPaneNewExecutor();
	~ScrollPaneNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_SCROLLPANE_SCROLLPANENEWEXECUTOR_H
