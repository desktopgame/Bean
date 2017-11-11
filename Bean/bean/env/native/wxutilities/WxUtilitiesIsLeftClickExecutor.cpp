#include "WxUtilitiesIsLeftClickExecutor.h"
#include <wx/wx.h>

WxUtilitiesIsLeftClickExecutor::WxUtilitiesIsLeftClickExecutor() {
}

WxUtilitiesIsLeftClickExecutor::~WxUtilitiesIsLeftClickExecutor() {
}

Object_ * const WxUtilitiesIsLeftClickExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return getBoolean(wxGetMouseState().LeftIsDown());
}
