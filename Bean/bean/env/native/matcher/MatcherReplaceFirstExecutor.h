#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERREPLACEEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERREPLACEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherReplaceFirstExecutor : public TypedNativeMethodExecutor {
public:
	MatcherReplaceFirstExecutor();
	~MatcherReplaceFirstExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERREPLACEEXECUTOR_H
