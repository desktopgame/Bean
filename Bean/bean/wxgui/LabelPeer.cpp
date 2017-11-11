#include "LabelPeer.h"
#include "WxLabelEx.h"

//public method---
LabelPeer::LabelPeer(wxWindow* window) 
 : ComponentPeer<WxLabelEx>(new WxLabelEx(window, wxID_ANY, wxT(""))) {
}

LabelPeer::~LabelPeer() {
}

void LabelPeer::setText(std::string text) {
	getTarget()->SetLabel(text);
}

std::string LabelPeer::getText() {
	return getTarget()->GetLabel();
}
//---public method