#include "ButtonPeer.h"

//public method---
ButtonPeer::ButtonPeer(wxWindow* window)
 : ComponentPeer<WxButtonEx>(new WxButtonEx(window, wxID_ANY, wxT(""))) {
}

ButtonPeer::~ButtonPeer() {
}

void ButtonPeer::addPushListener(PushListener listener) {
	getTarget()->addPushListener(listener);
}

void ButtonPeer::removePushListenerAt(int index) {
	getTarget()->removePushListenerAt(index);
}

int ButtonPeer::getPushListenerCount() {
	return getTarget()->getPushListenerCount();
}

void ButtonPeer::setText(std::string text) {
	getTarget()->SetLabel(text);
}

std::string ButtonPeer::getText() {
	return getTarget()->GetLabel();
}
//---public method