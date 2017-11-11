#include "WxLabelEx.h"

//public method---
WxLabelEx::WxLabelEx(wxWindow* window, wxWindowID id, const wxString& label) 
 : wxStaticText(window, id, label, wxDefaultPosition, wxDefaultSize) {
}

WxLabelEx::~WxLabelEx() {
}
//---public method