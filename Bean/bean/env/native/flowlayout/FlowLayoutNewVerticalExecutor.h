#pragma once
#ifndef BEAN_ENV_NATIVE_FLOWLAYOUT_FLOWLAYOUTNEWVERTICALEXECUTOR_H
#define BEAN_ENV_NATIVE_FLOWLAYOUT_FLOWLAYOUTNEWVERTICALEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FlowLayoutNewVerticalExecutor : public TypedNativeMethodExecutor {
public:
	FlowLayoutNewVerticalExecutor();
	~FlowLayoutNewVerticalExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FLOWLAYOUT_FLOWLAYOUTNEWVERTICALEXECUTOR_H
