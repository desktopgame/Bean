#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDCANUNDOEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDCANUNDOEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldCanUndoExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldCanUndoExecutor();
	~TextFieldCanUndoExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDCANUNDOEXECUTOR_H
