#pragma once
#ifndef BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESGETMOUSEPOINTEXECUTOR_H
#define BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESGETMOUSEPOINTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class WxUtilitiesGetMousePointExecutor : public TypedNativeMethodExecutor {
public:
	WxUtilitiesGetMousePointExecutor();
	~WxUtilitiesGetMousePointExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESGETMOUSEPOINTEXECUTOR_H
