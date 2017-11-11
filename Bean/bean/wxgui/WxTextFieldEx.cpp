#include "WxTextFieldEx.h"

//public method---
WxTextFieldEx::WxTextFieldEx(wxWindow* window) 
 : wxTextCtrl(window, wxID_ANY, "", wxDefaultPosition, wxDefaultSize) {
}

WxTextFieldEx::~WxTextFieldEx() {
}
//---public method