#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERRESET2EXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERRESET2EXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherReset2Executor : public TypedNativeMethodExecutor {
public:
	MatcherReset2Executor();
	~MatcherReset2Executor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERRESET2EXECUTOR_H
