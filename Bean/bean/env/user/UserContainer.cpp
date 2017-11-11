#include "UserContainer.h"
#include "../../env/Package.h"
#include "../../wxgui/ComponentInterface.h"
#include "../../wxgui/ContainerInterface.h"

//public method---
UserContainer::UserContainer(ContainerInterface* containerInterface) 
 : UserComponent(dynamic_cast<ComponentInterface*>(containerInterface)) {
	this->containerInterface = containerInterface;
}

UserContainer::~UserContainer() {
}

void UserContainer::setLayout(wxSizer * sizer) {
	containerInterface->setLayout(sizer);
}

wxSizer * UserContainer::getLayout() {
	return containerInterface->getLayout();
}

wxWindow * UserContainer::getWindow() {
	return this->containerInterface->getWindow();
}
//---public method

//protected method---
void UserContainer::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Container"));
}
//---protected method