#include "PanelPeer.h"

//public method---
PanelPeer::PanelPeer(wxWindow* window) 
 : ContainerPeer<WxPanelEx>(new WxPanelEx(window, wxID_ANY)) {
}

PanelPeer::~PanelPeer() {
}
//---public method