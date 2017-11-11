#pragma once
#ifndef BEAN_ENV_NATIVE_BUTTON_BUTTONGETTEXTEXECUTOR_H
#define BEAN_ENV_NATIVE_BUTTON_BUTTONGETTEXTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ButtonGetTextExecutor : public TypedNativeMethodExecutor {
public:
	ButtonGetTextExecutor();
	~ButtonGetTextExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BUTTON_BUTTONGETTEXTEXECUTOR_H
