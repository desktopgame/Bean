#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDREDOEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDREDOEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldRedoExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldRedoExecutor();
	~TextFieldRedoExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDREDOEXECUTOR_H
