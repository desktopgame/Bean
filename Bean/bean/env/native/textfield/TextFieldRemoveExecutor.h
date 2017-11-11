#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDREMOVEEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDREMOVEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldRemoveExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldRemoveExecutor();
	~TextFieldRemoveExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDREMOVEEXECUTOR_H
