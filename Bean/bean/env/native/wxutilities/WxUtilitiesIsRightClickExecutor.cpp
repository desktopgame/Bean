#include "WxUtilitiesIsRightClickExecutor.h"
#include <wx/wx.h>

WxUtilitiesIsRightClickExecutor::WxUtilitiesIsRightClickExecutor() {
}


WxUtilitiesIsRightClickExecutor::~WxUtilitiesIsRightClickExecutor() {
}

Object_ * const WxUtilitiesIsRightClickExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getBoolean(wxGetMouseState().RightIsDown());
}
