#pragma once
#ifndef BEAN_ENV_NATIVE_BUTTON_BUTTONADDPUSHLISTENEREXECUTOR_H
#define BEAN_ENV_NATIVE_BUTTON_BUTTONADDPUSHLISTENEREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ButtonAddPushListenerExecutor : public TypedNativeMethodExecutor {
public:
	ButtonAddPushListenerExecutor();
	~ButtonAddPushListenerExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BUTTON_BUTTONADDPUSHLISTENEREXECUTOR_H
