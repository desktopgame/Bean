#include "UserMenuItem.h"
#include "../Package.h"
#include "../../util/NotImplException.h"

//public method---
UserMenuItem::UserMenuItem(wxMenuItem * item) : UserMenuElement() {
	this->itemEx = item;
}

UserMenuItem::UserMenuItem() 
 : UserMenuItem(new wxMenuItem()) {
}

UserMenuItem::~UserMenuItem() {
}

void UserMenuItem::setText(std::string text) {
//	this->itemEx->SetText(text);
	itemEx->SetItemLabel(text);
//	itemEx->SetText(text);
	this->label = text;
}

std::string UserMenuItem::getText() {
//	return itemEx->GetText();
	return itemEx->GetItemLabel();
//	return label;
}

wxMenuItem * UserMenuItem::getWXMenuItem() {
	return this->itemEx;
}

wxMenu * UserMenuItem::getWXMenu() {
	return nullptr;
}

void UserMenuItem::setSelected(bool isSelected) {
	if (!itemEx->IsCheckable()) {
		throw NotImplException();
	}
	itemEx->Check(isSelected);
}

bool UserMenuItem::isSelected() {
	if (!itemEx->IsCheckable()) {
		throw NotImplException();
	}
	return itemEx->IsChecked();
}
//---public method

//protected method---
void UserMenuItem::lazyLoading() {
	if (itemEx->IsCheckable()) {
		setClass(Package::getClassOrLoad("api.wxgui.CheckBoxMenuItem"));
	} else {
		setClass(Package::getClassOrLoad("api.wxgui.MenuItem"));
	}
}
//---protected method