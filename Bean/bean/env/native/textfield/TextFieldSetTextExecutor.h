#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDSETTEXTEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDSETTEXTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldSetTextExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldSetTextExecutor();
	~TextFieldSetTextExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDSETTEXTEXECUTOR_H
