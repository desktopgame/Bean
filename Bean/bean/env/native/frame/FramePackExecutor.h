#pragma once
#ifndef BEAN_ENV_NATIVE_FRAME_FRAMEPACKEXECUTOR_H
#define BEAN_ENV_NATIVE_FRAME_FRAMEPACKEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FramePackExecutor : public TypedNativeMethodExecutor {
public:
	FramePackExecutor();
	~FramePackExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FRAME_FRAMEPACKEXECUTOR_H
