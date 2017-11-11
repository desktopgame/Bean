#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERENDEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERENDEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherEndExecutor : public TypedNativeMethodExecutor {
public:
	MatcherEndExecutor();
	~MatcherEndExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERENDEXECUTOR_H
