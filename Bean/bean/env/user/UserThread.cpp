#include "UserThread.h"
#include "../Boolean.h"
#include "../Null.h"
#include "../Package.h"
#include "../Runtime.h"
#include "../user/UserDelegate.h"

//public method---
UserThread::UserThread(std::string name) : Object_(nullptr) {
	ThreadSPtr tptr = Runtime::newThread(name);
	this->thread = std::weak_ptr<Thread>(tptr);
	this->ud = nullptr;
	thread.lock()->setOwner(this);
	setClass(Package::getClass("api.Thread"));
}

UserThread::UserThread(ThreadSPtr t) : Object_(nullptr) {
	this->thread = t;
	setClass(Package::getClass("api.Thread"));
}

UserThread::~UserThread() {
}

void UserThread::start(UserDelegate * ud) {
	this->ud = ud;
	getThread()->start(ud);
}

UserDelegate * UserThread::getDelegate() const {
	return this->ud;
}

std::vector<Object_*> UserThread::getVirtualField() {
	auto ret = std::vector<Object_*>();
	ret.push_back(this->ud);
	return concatDynamicMembers(ret);
}

Object_ * UserThread::clone() {
	return nullptr;
}

ThreadSPtr UserThread::getThread() {
	return this->thread.lock();
}

bool UserThread::die() {
	ThreadSPtr th = getThread();
	if (!th) {
		return false;
	}
	if (th) {
		th->setOwner(nullptr);
		th->exit();
	}
	this->ud = nullptr;
	delete this;
	return true;
}

UserThread * UserThread::asUserThread() {
	return this;
}

UserThread * const UserThread::getCurrent() {
	return Thread::getCurrent()->getOwner();
}
//---public method

//protected method---
void UserThread::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Thread"));
}
//---protected method
