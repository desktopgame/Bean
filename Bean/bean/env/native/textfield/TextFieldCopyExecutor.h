#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDCOPYEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDCOPYEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldCopyExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldCopyExecutor();
	~TextFieldCopyExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDCOPYEXECUTOR_H
