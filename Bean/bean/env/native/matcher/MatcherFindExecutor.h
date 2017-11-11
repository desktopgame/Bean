#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERFINDEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERFINDEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherFindExecutor : public TypedNativeMethodExecutor {
public:
	MatcherFindExecutor();
	~MatcherFindExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERFINDEXECUTOR_H
