#pragma once
#ifndef BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXREMOVEPAINTLISTENERATEXECUTOR_H
#define BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXREMOVEPAINTLISTENERATEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class PaintBoxRemovePaintListenerAtExecutor : public TypedNativeMethodExecutor {
public:
	PaintBoxRemovePaintListenerAtExecutor();
	~PaintBoxRemovePaintListenerAtExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXREMOVEPAINTLISTENERATEXECUTOR_H
