#include "WxButtonEx.h"
#include <iostream>
#include "../util/Memory.h"

//public method---
WxButtonEx::WxButtonEx(wxWindow* parent, wxWindowID id, const wxString& label)
 : wxButton(parent, id, label, wxDefaultPosition, wxDefaultSize) {
	this->pushListenerList = std::vector<PushListener>();
	Connect(wxID_ANY, wxEVT_BUTTON, wxCommandEventHandler(WxButtonEx::OnPush));
}

WxButtonEx::~WxButtonEx() {
}

void WxButtonEx::addPushListener(PushListener listener) {
	pushListenerList.push_back(listener);
}

void WxButtonEx::removePushListenerAt(int index) {
	pushListenerList.erase(pushListenerList.begin() + index);
}

int WxButtonEx::getPushListenerCount() const {
	return static_cast<int>(pushListenerList.size());
}

void WxButtonEx::firePushEvent(WxButtonEx * sender, wxCommandEvent & e) {
	for (PushListener li : pushListenerList) {
		li(sender, e);
	}
}

void WxButtonEx::OnPush(wxCommandEvent & e) {
	firePushEvent(this, e);
}
//---public method