#include "WxUtilitiesIsMiddleClickExecutor.h"
#include <wx/wx.h>

WxUtilitiesIsMiddleClickExecutor::WxUtilitiesIsMiddleClickExecutor() {
}

WxUtilitiesIsMiddleClickExecutor::~WxUtilitiesIsMiddleClickExecutor() {
}

Object_ * const WxUtilitiesIsMiddleClickExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getBoolean(wxGetMouseState().MiddleIsDown());
}
