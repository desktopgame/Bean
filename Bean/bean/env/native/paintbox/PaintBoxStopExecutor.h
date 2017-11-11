#pragma once
#ifndef BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXSTOPEXECUTOR_H
#define BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXSTOPEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class PaintBoxStopExecutor : public TypedNativeMethodExecutor {
public:
	PaintBoxStopExecutor();
	~PaintBoxStopExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXSTOPEXECUTOR_H
