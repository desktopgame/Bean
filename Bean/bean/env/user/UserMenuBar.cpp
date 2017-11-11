#include "UserMenuBar.h"
#include "../Package.h"
//public method---
UserMenuBar::UserMenuBar(MenuBarInterface* menuBarInterface) 
 : UserContainer(dynamic_cast<ContainerInterface*>(menuBarInterface)) {
	this->menuBarInterface = menuBarInterface;
}

UserMenuBar::~UserMenuBar() {
	delete menuBarInterface;
}

wxMenu* UserMenuBar::addMenu(std::string label) {
	return menuBarInterface->addMenu(label);
}

void UserMenuBar::removeMenuAt(int index) {
	menuBarInterface->removeMenuAt(index);
}

int UserMenuBar::getMenuCount() {
	return menuBarInterface->getMenuCount();
}

wxMenuBar * UserMenuBar::getWXMenuBar() {
	return menuBarInterface->getWXMenuBar();
}
//---public method

//protected method---
void UserMenuBar::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.MenuBar"));
}
//---protected method