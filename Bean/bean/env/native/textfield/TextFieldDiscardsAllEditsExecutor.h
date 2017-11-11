#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDDISCARDSALLEDITSEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDDISCARDSALLEDITSEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldDiscardsAllEditsExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldDiscardsAllEditsExecutor();
	~TextFieldDiscardsAllEditsExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDDISCARDSALLEDITSEXECUTOR_H
