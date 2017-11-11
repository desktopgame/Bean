#include "UserMutex.h"
#include "../Boolean.h"
#include "../Null.h"
#include "../Package.h"

//public method---
UserMutex::UserMutex() : Object_(nullptr) {
}

UserMutex::~UserMutex() {
}

void UserMutex::lock() {
	mutex.lock();
}

void UserMutex::unlock() {
	mutex.unlock();
}

Object_ * UserMutex::clone() {
	return nullptr;
}
//---public method


//protected method---
void UserMutex::lazyLoading() {
	setClass(Package::getClass("api.Mutex"));
}
//---protected method
