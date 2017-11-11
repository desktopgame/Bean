#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGSUBSTRINGEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGSUBSTRINGEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringSubstringExecutor : public TypedNativeMethodExecutor {
public:
	StringSubstringExecutor();
	~StringSubstringExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};


#endif // !BEAN_ENV_NATIVE_STRING_STRINGSUBSTRINGEXECUTOR_H
