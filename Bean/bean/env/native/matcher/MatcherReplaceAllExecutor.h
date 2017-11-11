#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERREPLACEALLEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERREPLACEALLEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherReplaceAllExecutor : public TypedNativeMethodExecutor {
public:
	MatcherReplaceAllExecutor();
	~MatcherReplaceAllExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERREPLACEALLEXECUTOR_H
