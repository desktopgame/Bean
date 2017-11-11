#pragma once
#ifndef BEAN_ENV_NATIVE_STRING_STRINGSTARTSWITHEXECUTOR_H
#define BEAN_ENV_NATIVE_STRING_STRINGSTARTSWITHEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class StringStartsWithExecutor : public TypedNativeMethodExecutor {
public:
	StringStartsWithExecutor();
	~StringStartsWithExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_STRING_STRINGSTARTSWITHEXECUTOR_H
