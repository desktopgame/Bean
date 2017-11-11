#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHEREND2EXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHEREND2EXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherEnd2Executor : public TypedNativeMethodExecutor {
public:
	MatcherEnd2Executor();
	~MatcherEnd2Executor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHEREND2EXECUTOR_H
