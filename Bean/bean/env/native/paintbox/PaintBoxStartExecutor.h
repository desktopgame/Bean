#pragma once
#ifndef BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXSTARTEXECUTOR_H
#define BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXSTARTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class PaintBoxStartExecutor : public TypedNativeMethodExecutor {
public:
	PaintBoxStartExecutor();
	~PaintBoxStartExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_PAINTBOX_PAINTBOXSTARTEXECUTOR_H
