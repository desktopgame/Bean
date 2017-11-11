#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGINSERTEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGINSERTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringInsertExecutor : public TypedNativeMethodExecutor {
public:
	StringInsertExecutor();
	~StringInsertExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGINSERTEXECUTOR_H
