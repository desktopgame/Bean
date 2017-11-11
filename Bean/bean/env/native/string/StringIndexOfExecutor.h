#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGINDEXOFEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGINDEXOFEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringIndexOfExecutor : public TypedNativeMethodExecutor {
public:
	StringIndexOfExecutor();
	~StringIndexOfExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGINDEXOFEXECUTOR_H
