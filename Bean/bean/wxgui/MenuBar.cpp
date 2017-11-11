#include "MenuBar.h"

//public method---
MenuBar::MenuBar() 
 : Container<MenuBarPeer>(new MenuBarPeer()) {
}

MenuBar::~MenuBar() {
}

wxMenu* MenuBar::addMenu(std::string label) {
	return getPeer()->addMenu(label);
}

void MenuBar::removeMenuAt(int index) {
	getPeer()->removeMenuAt(index);
}

int MenuBar::getMenuCount() {
	return getPeer()->getMenuCount();
}

wxMenuBar * MenuBar::getWXMenuBar() {
	return getPeer()->getWXMenuBar();
}
//---public method