#pragma once
#ifndef BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDNEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class TextFieldNewExecutor : public TypedNativeMethodExecutor {
public:
	TextFieldNewExecutor();
	~TextFieldNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_TEXTFIELD_TEXTFIELDNEWEXECUTOR_H
