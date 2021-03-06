#pragma once
#ifndef BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESISLEFTCLICKEXECUTOR_H
#define BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESISLEFTCLICKEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class WxUtilitiesIsLeftClickExecutor : public TypedNativeMethodExecutor {
public:
	WxUtilitiesIsLeftClickExecutor();
	~WxUtilitiesIsLeftClickExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESISLEFTCLICKEXECUTOR_H
