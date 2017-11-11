#include "WxScrollPaneEx.h"

//public method---
WxScrollPaneEx::WxScrollPaneEx(wxWindow* window) 
 : wxScrolledWindow(window, wxID_ANY, wxDefaultPosition, wxDefaultSize){
	//this->SetSizer(new wxBoxSizer(wxHORIZONTAL));
	this->FitInside();
	//SetVirtualSize(292, 292);
	//SetScrollbars(1,1,256,256,0,0);
}

WxScrollPaneEx::~WxScrollPaneEx() {
}
//---public method