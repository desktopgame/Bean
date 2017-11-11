#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERALLEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERALLEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherAllExecutor : public TypedNativeMethodExecutor {
public:
	MatcherAllExecutor();
	~MatcherAllExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERALLEXECUTOR_H
