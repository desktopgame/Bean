#pragma once
#ifndef BEAN_ENV_NATIVE_FLOWLAYOUT_FLOWLAYOUTNEWHORIZONTALEXECUTOR_H
#define BEAN_ENV_NATIVE_FLOWLAYOUT_FLOWLAYOUTNEWHORIZONTALEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FlowLayoutNewHorizontalExecutor : public TypedNativeMethodExecutor {
public:
	FlowLayoutNewHorizontalExecutor();
	~FlowLayoutNewHorizontalExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FLOWLAYOUT_FLOWLAYOUTNEWHORIZONTALEXECUTOR_H
