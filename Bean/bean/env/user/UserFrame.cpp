#include "UserFrame.h"
#include "../Package.h"
#include "../../wxgui/FrameInterface.h"
#include "../../wxgui/WindowInterface.h"

//public method---
UserFrame::UserFrame(FrameInterface* frameInterface) 
 : UserWindow(dynamic_cast<WindowInterface*>(frameInterface)){
	this->frameInterface = frameInterface;
}

UserFrame::~UserFrame() {
}

void UserFrame::mainLoop() {
	frameInterface->mainLoop();
}

void UserFrame::pack() {
	frameInterface->pack();
}

wxPanel * UserFrame::getContentPane() const {
	return this->frameInterface->getContentPane();
}

void UserFrame::setMenuBar(wxMenuBar * menuBar) {
	frameInterface->setMenuBar(menuBar);
}

wxMenuBar * UserFrame::getMenuBar() {
	return frameInterface->getMenuBar();
}

void UserFrame::createStatusBar(int length) {
	frameInterface->createStatusBar(length);
}

void UserFrame::printStatus(int index, std::string text) {
	frameInterface->printStatus(index, text);
}
//---public method

//protected method---
void UserFrame::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Frame"));
}
//---protected method
