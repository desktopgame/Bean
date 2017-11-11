#include "UserWindow.h"
#include "../../env/Package.h"
#include "../../wxgui/ContainerInterface.h"
#include "../../wxgui/WindowInterface.h"

//public method---
UserWindow::UserWindow(WindowInterface* windowInterface) 
 : UserContainer(dynamic_cast<ContainerInterface*>(windowInterface)) {
	this->windowInterface = windowInterface;
}

UserWindow::~UserWindow() {
}

void UserWindow::setTitle(std::string title) {
	windowInterface->setTitle(title);
}

std::string UserWindow::getTitle() const {
	return windowInterface->getTitle();
}
//---public method

//protected method---
void UserWindow::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Window"));
}
//---protected method