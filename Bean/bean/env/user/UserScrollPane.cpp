#include "UserScrollPane.h"
#include "../Package.h"
#include "../../wxgui/ContainerInterface.h"
#include "../../wxgui/ScrollPaneInterface.h"

//public method---
UserScrollPane::UserScrollPane(ScrollPaneInterface* scrollPaneInterface) 
 : UserContainer(dynamic_cast<ContainerInterface*>(scrollPaneInterface)) {
	this->scrollPaneInterface = scrollPaneInterface;
}

UserScrollPane::~UserScrollPane() {
}
//---public method

//protected method---
void UserScrollPane::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.ScrollPane"));
}
//---protected method