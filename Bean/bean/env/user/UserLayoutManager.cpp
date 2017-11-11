#include "UserLayoutManager.h"
#include "../Boolean.h"
#include "../Null.h"
#include "../Object_.h"
#include "../Package.h"

//public method---
UserLayoutManager::UserLayoutManager(LayoutManagerInterface* layoutManagerInterface)
 : Object_(nullptr) {
	this->layoutManagerInterface = layoutManagerInterface;
}

UserLayoutManager::~UserLayoutManager() {
	delete layoutManagerInterface;
}

Object_ * UserLayoutManager::clone() {
	return Null::getInstance();
}

void UserLayoutManager::addComponent(wxWindow * c, wxSizerFlags flags) {
	layoutManagerInterface->addComponent(c, flags);
}

void UserLayoutManager::addSpace(int size) {
	layoutManagerInterface->addSpace(size);
}

void UserLayoutManager::addStretch() {
	layoutManagerInterface->addStretch();
}

void UserLayoutManager::removeComponentAt(int index) {
	layoutManagerInterface->removeComponentAt(index);
}

int UserLayoutManager::getComponentCount() {
	return layoutManagerInterface->getComponentCount();
}

void UserLayoutManager::setMinSize(wxSize size) {
	layoutManagerInterface->setMinSize(size);
}

wxSize UserLayoutManager::getMinSize() {
	return layoutManagerInterface->getMinSize();
}

void UserLayoutManager::setFitSize(wxSize size) {
	layoutManagerInterface->setFitSize(size);
}

wxSize UserLayoutManager::getFitSize() {
	return layoutManagerInterface->getFitSize();
}

void UserLayoutManager::setMaxSize(wxSize size) {
	layoutManagerInterface->setMaxSize(size);
}

wxSize UserLayoutManager::getMaxSize() {
	return layoutManagerInterface->getMaxSize();
}

void UserLayoutManager::doLayout() {
	layoutManagerInterface->doLayout();
}

wxSizer * UserLayoutManager::getWX() {
	return layoutManagerInterface->getWX();
}
//---public method

//protected method---
void UserLayoutManager::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.LayoutManager"));
}
//---protected method
