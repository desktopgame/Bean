#pragma once
#ifndef BEAN_ENV_NATIVE_PATTERN_PATTERNCOMPILEEXECUTOR_H
#define BEAN_ENV_NATIVE_PATTERN_PATTERNCOMPILEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class PatternCompileExecutor : public TypedNativeMethodExecutor {
public:
	PatternCompileExecutor();
	~PatternCompileExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_PATTERN_PATTERNCOMPILEEXECUTOR_H
