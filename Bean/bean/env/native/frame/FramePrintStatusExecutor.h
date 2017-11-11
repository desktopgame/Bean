#pragma once
#ifndef BEAN_ENV_NATIVE_FRAME_FRAMEPRINTSTATUSBAREXECUTOR_H
#define BEAN_ENV_NATIVE_FRAME_FRAMEPRINTSTATUSBAREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FramePrintStatusExecutor : public TypedNativeMethodExecutor {
public:
	FramePrintStatusExecutor();
	~FramePrintStatusExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FRAME_FRAMEPRINTSTATUSBAREXECUTOR_H
