#include "UserLabel.h"
#include "../Package.h"
#include "../../wxgui/ComponentInterface.h"
#include "../../wxgui/LabelInterface.h"

//public method---
UserLabel::UserLabel(LabelInterface* labelInterface) 
 : UserComponent(dynamic_cast<ComponentInterface*>(labelInterface)) {
	this->labelInterface = labelInterface;
}

UserLabel::~UserLabel() {
	delete labelInterface;
}

void UserLabel::setText(std::string text) {
	labelInterface->setText(text);
}

std::string UserLabel::getText() {
	return labelInterface->getText();
}
//---public method

//protected method---
void UserLabel::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Label"));
}
//---protected method