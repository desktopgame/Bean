#pragma once
#ifndef BEAN_ENV_NATIVE_BUTTON_BUTTONSETTEXTEXECUTOR_H
#define BEAN_ENV_NATIVE_BUTTON_BUTTONSETTEXTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class ButtonSetTextExecutor : public TypedNativeMethodExecutor {
public:
	ButtonSetTextExecutor();
	~ButtonSetTextExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BUTTON_BUTTONSETTEXTEXECUTOR_H
