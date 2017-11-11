#include "UserDelegate.h"
#include "../Boolean.h"
#include "../Delegate.h"
#include "../Null.h"
#include "../Package.h"

//public method---
UserDelegate::UserDelegate(ClassLoaderSPtr classLoader, Delegate* d) : Object_(nullptr) {
	setClass(Package::getClass("api.Delegate"));
	this->classLoader = classLoader;
	this->d = d;
	this->dynamicMethod = false;
}

UserDelegate::~UserDelegate() {
	delete d;
}

ClassLoaderSPtr UserDelegate::getCapture() const {
	return classLoader;
}

Delegate * const UserDelegate::getDelegate() const {
	d->setDynamicMethod(isDynamicMethod());
	return d;
}

Object_* UserDelegate::call(ThreadSPtr t, std::vector<Object_*> args) {
	return getDelegate()->call(t, classLoader, args);
}

Object_* UserDelegate::call(std::vector<Object_*> args) {
	return getDelegate()->call(classLoader, args);
}

void UserDelegate::setDynamicMethod(bool b) {
	this->dynamicMethod = b;
}

bool UserDelegate::isDynamicMethod() const {
	return this->dynamicMethod;
}

Object_ * UserDelegate::clone() {
	return nullptr;
}

std::vector<Object_*> UserDelegate::getVirtualField() {
	return concatDynamicMembers(d->getVirtualField(getCapture()));
}

UserDelegate * UserDelegate::asUserDelegate() {
	return this;
}
//---public method

//protected method---
void UserDelegate::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Delegate"));
}
//---protected method
