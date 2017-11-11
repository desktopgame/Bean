#pragma once
#ifndef BEAN_ENV_NATIVE_MATCHER_MATCHERGROUPCOUNTEXECUTOR_H
#define BEAN_ENV_NATIVE_MATCHER_MATCHERGROUPCOUNTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class MatcherGroupCountExecutor : public TypedNativeMethodExecutor {
public:
	MatcherGroupCountExecutor();
	~MatcherGroupCountExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_MATCHER_MATCHERGROUPCOUNTEXECUTOR_H
