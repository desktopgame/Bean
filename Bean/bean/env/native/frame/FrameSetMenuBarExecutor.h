#pragma once
#ifndef BEAN_ENV_NATIVE_FRAME_FRAMESETMENUBAREXECUTOR_H
#define BEAN_ENV_NATIVE_FRAME_FRAMESETMENUBAREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FrameSetMenuBarExecutor : public TypedNativeMethodExecutor {
public:
	FrameSetMenuBarExecutor();
	~FrameSetMenuBarExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FRAME_FRAMESETMENUBAREXECUTOR_H
