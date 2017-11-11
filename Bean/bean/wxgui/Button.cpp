#include "Button.h"
#include "WxButtonEx.h"

//public method---
Button::Button(ContainerInterface* parent)
 : Component<ButtonPeer>(new ButtonPeer(parent->getWindow())) {
}

Button::~Button() {
}

void Button::addPushListener(PushListener listener) {
	getPeer()->addPushListener(listener);
}

void Button::removePushListenerAt(int index) {
	getPeer()->removePushListenerAt(index);
}

int Button::getPushListenerCount() {
	return getPeer()->getPushListenerCount();
}

void Button::setText(std::string text) {
	getPeer()->setText(text);
}

std::string Button::getText() {
	return getPeer()->getText();
}
//---public method