#pragma once
#ifndef BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXADDPAINTLISTENEREXECUTOR_H
#define BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXADDPAINTLISTENEREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class PaintBoxAddPaintListenerExecutor : public TypedNativeMethodExecutor {
public:
	PaintBoxAddPaintListenerExecutor();
	~PaintBoxAddPaintListenerExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXADDPAINTLISTENEREXECUTOR_H
