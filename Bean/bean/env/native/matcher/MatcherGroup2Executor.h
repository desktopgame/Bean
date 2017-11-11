#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERGROUP2EXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERGROUP2EXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherGroup2Executor : public TypedNativeMethodExecutor {
public:
	MatcherGroup2Executor();
	~MatcherGroup2Executor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERGROUP2EXECUTOR_H
