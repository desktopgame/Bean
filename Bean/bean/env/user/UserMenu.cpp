#include "UserMenu.h"
#include "../Boolean.h"
#include "../Null.h"
#include "../Package.h"
#include "../../util/NotImplException.h"

//public method---
UserMenu::UserMenu(wxMenu * menu) : UserMenuElement() {
	this->menuEx = menu;
}

UserMenu::UserMenu()
 : UserMenu(new wxMenu()) {
}

UserMenu::~UserMenu() {
}

void UserMenu::setText(std::string text) {
	this->label = text;
	//	menuEx->SetTitle(text);
}

std::string UserMenu::getText() {
	return this->label;
//	return menuEx->GetTitle();
}

wxMenuItem* UserMenu::addMenuItem(std::string label) {
	wxMenuItem* item = menuEx->Append(wxID_ANY, label);
	return item;
//	return nullptr;
}

wxMenuItem * UserMenu::addCheckBoxMenuItem(std::string label) {
	wxMenuItem* item = menuEx->AppendCheckItem(wxID_ANY, label);
	item->SetCheckable(true);
	return item;
}

wxMenu* UserMenu::addMenu(std::string label) {
//	menuEx->AppendSubMenu(menu, menu->GetTitle());
	wxMenu* ret = new wxMenu();
	menuEx->AppendSubMenu(ret, label);
	return ret;
}

void UserMenu::addSeparator() {
	menuEx->AppendSeparator();
}

void UserMenu::removeSubElementAt(int index) {
	menuEx->Remove(index);
}

int UserMenu::getSubElementCount() {
	return menuEx->GetMenuItemCount();
}

wxMenuItem * UserMenu::getWXMenuItem() {
	return nullptr;
}

wxMenu * UserMenu::getWXMenu() {
	return this->menuEx;
}

void UserMenu::setSelected(bool isSelected) {
	throw NotImplException();
}

bool UserMenu::isSelected() {
	throw NotImplException();
}
//---public method

//protected method---
void UserMenu::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Menu"));
}
//---protected method
