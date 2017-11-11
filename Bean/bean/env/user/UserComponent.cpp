#include "UserComponent.h"
#include "../../env/Boolean.h"
#include "../../env/Null.h"
#include "../../env/Package.h"
#include "../../wxgui/ComponentInterface.h"
#include "../../wxgui/FrameInterface.h"
#include "../../wxgui/WindowInterface.h"

//public method---
UserComponent::UserComponent(ComponentInterface* componentInterface) 
 : Object_(nullptr) {
	this->componentInterface = componentInterface;
}

UserComponent::~UserComponent() {
}

void UserComponent::repaint() {
	componentInterface->repaint();
}

void UserComponent::setX(int x) {
	componentInterface->setX(x);
}

int UserComponent::getX() {
	return componentInterface->getX();
}

void UserComponent::setY(int y) {
	componentInterface->setY(y);
}

int UserComponent::getY() {
	return componentInterface->getY();
}

void UserComponent::setWidth(int w) {
	componentInterface->setWidth(w);
}

int UserComponent::getWidth() {
	return componentInterface->getWidth();
}

void UserComponent::setHeight(int h) {
	componentInterface->setHeight(h);
}

int UserComponent::getHeight() {
	return componentInterface->getHeight();
}

void UserComponent::setMinSize(wxSize size) {
	componentInterface->setMinSize(size);
}

wxSize UserComponent::getMinSize() {
	return componentInterface->getMinSize();
}

void UserComponent::setFitSize(wxSize size) {
	componentInterface->setFitSize(size);
}

wxSize UserComponent::getFitSize() {
	return componentInterface->getFitSize();
}

void UserComponent::setMaxSize(wxSize size) {
	componentInterface->setMaxSize(size);
}

wxSize UserComponent::getMaxSize() {
	return componentInterface->getMaxSize();
}

void UserComponent::setForeground(wxColor foreColor) {
	componentInterface->setForeground(foreColor);
}

wxColor UserComponent::getForeground() {
	return componentInterface->getForeground();
}

void UserComponent::setBackground(wxColor backColor) {
	componentInterface->setBackground(backColor);
}

wxColor UserComponent::getBackground() {
	return componentInterface->getBackground();
}

wxWindow * UserComponent::getWX() {
	return componentInterface->getWX();
}

Object_ * UserComponent::clone() {
	return nullptr;
}

UserComponent * UserComponent::asUserComponent() {
	return this;
}
//---public method

//protected method---
void UserComponent::lazyLoading() {
	setClass(Package::getClass("api.wxgui.Component"));
}
//---protected method
