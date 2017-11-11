#pragma once
#ifndef BEAN_ENV_NATIVE_PATTERN_PATTERNMATCHEREXECUTOR_H
#define BEAN_ENV_NATIVE_PATTERN_PATTERNMATCHEREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class PatternMatcherExecutor : public TypedNativeMethodExecutor {
public:
	PatternMatcherExecutor();
	~PatternMatcherExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_PATTERN_PATTERNMATCHEREXECUTOR_H
