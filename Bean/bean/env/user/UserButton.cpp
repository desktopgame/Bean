#include "UserButton.h"
#include "UserArray.h"
#include "UserDelegate.h"
#include "../Delegate.h"
#include "../Object_.h"
#include "../Package.h"
#include "../../wxgui/ButtonInterface.h"
#include "../../wxgui/ComponentInterface.h"
#include "../../wxgui/EventSystem.h"
#include "../../wxgui/WxButtonEx.h"

//public method---
UserButton::UserButton(ButtonInterface* buttonInterface) 
 : UserComponent(dynamic_cast<ComponentInterface*>(buttonInterface)) {
	this->buttonInterface = buttonInterface;
	this->pushDelegateVector = std::vector<UserDelegate*>();
	buttonInterface->addPushListener([&](WxButtonEx* sender, const wxCommandEvent& e) { filterEvent(sender, e); });
}

UserButton::~UserButton() {
	pushDelegateVector.clear();
	delete buttonInterface;
}

void UserButton::addPushListener(UserDelegate * d) {
	pushDelegateVector.push_back(d);
}

void UserButton::addPushListener(PushListener listener) {
	buttonInterface->addPushListener(listener);
}

void UserButton::removePushListenerAt(int index) {
	pushDelegateVector.erase(pushDelegateVector.begin() + index);
}

int UserButton::getPushListenerCount() {
	return static_cast<int>(pushDelegateVector.size());
}

void UserButton::setText(std::string text) {
	buttonInterface->setText(text);
}

std::string UserButton::getText() {
	return buttonInterface->getText();
}

std::vector<Object_*> UserButton::getVirtualField() {
//	return this->pushDelegateVector;
	return concatDynamicMembers(std::vector<Object_*>(pushDelegateVector.begin(), pushDelegateVector.end()));
}

void UserButton::filterEvent(WxButtonEx * sender, const wxCommandEvent & e) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(this);
	EventSystem::postEvent(pushDelegateVector, args);
}
//---public method

//protected method---
void UserButton::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Button"));
}
//---protected method
