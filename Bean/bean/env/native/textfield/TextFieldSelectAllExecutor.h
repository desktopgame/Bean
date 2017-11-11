#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDSELECTALLEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDSELECTALLEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldSelectAllExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldSelectAllExecutor();
	~TextFieldSelectAllExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDSELECTALLEXECUTOR_H
