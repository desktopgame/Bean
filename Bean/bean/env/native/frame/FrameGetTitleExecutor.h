#pragma once
#ifndef BEAN_ENV_NATIVE_FRAME_FRAMEGETTITLEEXECUTOR_H
#define BEAN_ENV_NATIVE_FRAME_FRAMEGETTITLEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FrameGetTitleExecutor : public TypedNativeMethodExecutor {
public:
	FrameGetTitleExecutor();
	~FrameGetTitleExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FRAME_FRAMEGETTITLEEXECUTOR_H
