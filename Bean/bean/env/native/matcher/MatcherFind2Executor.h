#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERFIND2EXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERFIND2EXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherFind2Executor : public TypedNativeMethodExecutor {
public:
	MatcherFind2Executor();
	~MatcherFind2Executor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERFIND2EXECUTOR_H
