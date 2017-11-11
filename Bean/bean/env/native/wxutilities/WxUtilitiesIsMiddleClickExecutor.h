#pragma once
#ifndef BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESISMIDDLECLICKEXECUTOR_H
#define BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESISMIDDLECLICKEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class WxUtilitiesIsMiddleClickExecutor : public TypedNativeMethodExecutor {
public:
	WxUtilitiesIsMiddleClickExecutor();
	~WxUtilitiesIsMiddleClickExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESISMIDDLECLICKEXECUTOR_H
