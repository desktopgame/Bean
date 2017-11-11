#pragma once
#ifndef BEAN_ENV_NATIVE_BUTTON_BUTTONREMOVEPUSHLISTENERATEXECUTOR_H
#define BEAN_ENV_NATIVE_BUTTON_BUTTONREMOVEPUSHLISTENERATEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ButtonRemovePushListenerAtExecutor : public TypedNativeMethodExecutor {
public:
	ButtonRemovePushListenerAtExecutor();
	~ButtonRemovePushListenerAtExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BUTTON_BUTTONREMOVEPUSHLISTENERATEXECUTOR_H
