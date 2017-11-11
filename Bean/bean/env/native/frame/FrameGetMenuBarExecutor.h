#pragma once
#ifndef BEAN_ENV_NATIVE_FRAME_FRAMEGETMENUBAREXECUTOR_H
#define BEAN_ENV_NATIVE_FRAME_FRAMEGETMENUBAREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FrameGetMenuBarExecutor : public TypedNativeMethodExecutor {
public:
	FrameGetMenuBarExecutor();
	~FrameGetMenuBarExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FRAME_FRAMEGETMENUBAREXECUTOR_H
