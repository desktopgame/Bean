#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGLENGTHEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGLENGTHEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringLengthExecutor : public TypedNativeMethodExecutor {
public:
	StringLengthExecutor();
	~StringLengthExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGLENGTHEXECUTOR_H
