#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDGETCARETPOSITION_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDGETCARETPOSITION_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldGetCaretPositionExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldGetCaretPositionExecutor();
	~TextFieldGetCaretPositionExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDGETCARETPOSITION_H
