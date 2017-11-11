#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDINSERTEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDINSERTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldInsertExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldInsertExecutor();
	~TextFieldInsertExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDINSERTEXECUTOR_H
