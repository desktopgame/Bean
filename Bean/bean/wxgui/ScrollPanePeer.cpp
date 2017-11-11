#include "ScrollPanePeer.h"

//public method---
ScrollPanePeer::ScrollPanePeer(wxWindow* window)
 : ContainerPeer<WxScrollPaneEx>(new WxScrollPaneEx(window)) {
}

ScrollPanePeer::~ScrollPanePeer() {
}
//---public method