#include "UserFilePtr.h"
#include "../Boolean.h"
#include "../Class.h"
#include "../Null.h"
#include "../Package.h"

//public method---
UserFilePtr::UserFilePtr() : Object_(nullptr) {
	this->opened = 0;
	this->closed = 0;
}

UserFilePtr::~UserFilePtr() {
}

Object_ * UserFilePtr::clone() {
	return Null::getInstance();
}
//---public method

//protected method---
void UserFilePtr::lazyLoading() {
	setClass(Package::getClassOrLoad("api.io.FilePtr"));
}
//---protected method
