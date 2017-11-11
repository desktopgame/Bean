#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDUNDOEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDUNDOEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldUndoExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldUndoExecutor();
	~TextFieldUndoExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDUNDOEXECUTOR_H
