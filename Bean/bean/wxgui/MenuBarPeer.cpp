#include "MenuBarPeer.h"

//public method---
MenuBarPeer::MenuBarPeer() 
 : ContainerPeer<WxMenuBarEx>(new WxMenuBarEx()) {
}

MenuBarPeer::~MenuBarPeer() {
}

wxMenu* MenuBarPeer::addMenu(std::string label) {
	wxMenu* menu = new wxMenu();
	getTarget()->Append(menu, label);
	return menu;
}

void MenuBarPeer::removeMenuAt(int index) {
	getTarget()->Remove(index);
}

int MenuBarPeer::getMenuCount() {
	return static_cast<int>(getTarget()->GetMenuCount());
}

wxMenuBar * MenuBarPeer::getWXMenuBar() {
	return getTarget();
}
//---public method