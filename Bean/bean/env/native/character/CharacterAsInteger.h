#pragma once
#ifndef BEAN_ENV_NATIVE_CHARACTER_CHARACTERASINTEGER_H
#define BEAN_ENV_NATIVE_CHARACTER_CHARACTERASINTEGER_H
#include "../TypedNativeMethodExecutor.h"
class CharacterAsInteger : public TypedNativeMethodExecutor {
public:
	CharacterAsInteger();
	~CharacterAsInteger();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_CHARACTER_CHARACTERASINTEGER_H
