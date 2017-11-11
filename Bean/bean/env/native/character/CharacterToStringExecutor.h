#pragma once
#ifndef BEAN_ENV_NATIVE_CHARACTER_CHARACTERTOSTRINGEXECUTOR_H
#define BEAN_ENV_NATIVE_CHARACTER_CHARACTERTOSTRINGEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class CharacterToStringExecutor : public TypedNativeMethodExecutor {
public:
	CharacterToStringExecutor();
	~CharacterToStringExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_CHARACTER_CHARACTERTOSTRINGEXECUTOR_H
