#pragma once
#ifndef BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESGETKEYSTATEEXECUTOR_H
#define BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESGETKEYSTATEEXECUTOR_H
#include <wx/utils.h>
#include "../TypedNativeMethodExecutor.h"
class WxUtilitiesGetKeyStateExecutor : public TypedNativeMethodExecutor {
public:
	WxUtilitiesGetKeyStateExecutor();
	~WxUtilitiesGetKeyStateExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	wxKeyCode toKeycode(int i);
	int toWinKeycode(int i);
};
#endif // !BEAN_ENV_NATIVE_WXUTILITIES_WXUTILITIESGETKEYSTATEEXECUTOR_H
