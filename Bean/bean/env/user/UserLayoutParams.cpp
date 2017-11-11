#include "UserLayoutParams.h"
#include "../Boolean.h"
#include "../Null.h"
#include "../Package.h"

//public method---
UserLayoutParams::UserLayoutParams() 
 : Object_(nullptr) {
	this->flags = wxSizerFlags();
}

UserLayoutParams::~UserLayoutParams() {
}

const UserLayoutParams * UserLayoutParams::left() {
	flags.Left();
	return this;
}

const UserLayoutParams * UserLayoutParams::right() {
	flags.Right();
	return this;
}

const UserLayoutParams * UserLayoutParams::top() {
	flags.Top();
	return this;
}

const UserLayoutParams * UserLayoutParams::bottom() {
	flags.Bottom();
	return this;
}

const UserLayoutParams * UserLayoutParams::center() {
	flags.Center();
	return this;
}

const UserLayoutParams * UserLayoutParams::border(int thick) {
	flags.Border(wxALL, thick);
	return this;
}

const UserLayoutParams * UserLayoutParams::fill() {
	flags.Expand();
	return this;
}

wxSizerFlags * UserLayoutParams::getValue() {
	return &this->flags;
}

Object_ * UserLayoutParams::clone() {
	return Null::getInstance();
}
//---public method

//protected method---
void UserLayoutParams::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.LayoutParams"));
}
//---protected method
