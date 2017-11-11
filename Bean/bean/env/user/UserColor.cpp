#include "UserColor.h"
#include "../Boolean.h"
#include "../Null.h"
#include "../Package.h"

//public method---
UserColor::UserColor(float r, float g, float b, float a) 
 : Object_(nullptr) {
	this->color = wxColor(r, g, b, a);
}

UserColor::UserColor(float r, float g, float b) 
 : Object_(nullptr) {
	this->color = wxColor(r, g, b);
}

UserColor::UserColor(wxColor color) 
 : Object_(nullptr) {
	this->color = color;
}

UserColor::~UserColor() {
}

Object_ * UserColor::clone() {
	return nullptr;
}

Object_ * UserColor::equals(Object_ * right) {
	UserColor* col = dynamic_cast<UserColor*>(right);
	if (col == nullptr) return Boolean::getFalse();
	return Boolean::get(this->color == col->color);
}

wxColor UserColor::getWXColor() {
	return this->color;
}
//---public method

//protected method---
void UserColor::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Color"));
}
//---protected method
