#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGENDSWITHEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGENDSWITHEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringEndsWithExecutor : public TypedNativeMethodExecutor {
public:
	StringEndsWithExecutor();
	~StringEndsWithExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGENDSWITHEXECUTOR_H

