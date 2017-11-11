#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERSTARTEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERSTARTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherStartExecutor : public TypedNativeMethodExecutor {
public:
	MatcherStartExecutor();
	~MatcherStartExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERSTARTEXECUTOR_H
