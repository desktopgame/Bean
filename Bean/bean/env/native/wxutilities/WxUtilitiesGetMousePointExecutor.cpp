#include "WxUtilitiesGetMousePointExecutor.h"
#include <wx/wx.h>
#include "../../Class.h"

WxUtilitiesGetMousePointExecutor::WxUtilitiesGetMousePointExecutor() {
}

WxUtilitiesGetMousePointExecutor::~WxUtilitiesGetMousePointExecutor() {
}

Object_ * const WxUtilitiesGetMousePointExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	wxPoint pt = wxGetMousePosition();
	return Class::dynamicNewInstance("api.geom.Point2D", getInteger(pt.x), getInteger(pt.y));
}
