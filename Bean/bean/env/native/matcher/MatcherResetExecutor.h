#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERRESETEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERRESETEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherResetExecutor : public TypedNativeMethodExecutor {
public:
	MatcherResetExecutor();
	~MatcherResetExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERRESETEXECUTOR_H
