#include "UserVector.h"
#include <algorithm>
#include "../Class.h"
#include "../Object_.h"
#include "../Package.h"
#include "../gc/Heap.h"

//public method---
UserVector::UserVector()
 : Object_(nullptr) {
	this->objects = std::vector<Object_*>();
}

UserVector::~UserVector() {
}

Object_ * UserVector::clone() {
	return nullptr;
}

void UserVector::vadd(Object_ * obj) {
	Heap::getInstance()->writeBarrier(obj);
	objects.emplace_back(obj);
}

void UserVector::set(int index, Object_ * obj) {
	Heap::getInstance()->writeBarrier(obj);
	objects.assign(index, obj);
}

Object_ * UserVector::get(int index) {
	return objects.at(index);
}

void UserVector::insert(int index, Object_ * obj) {
	if (index >= size()) {
		vadd(obj);
		return;
	}
	if (index < 0) {
		index = 0;
	}
	Heap::getInstance()->writeBarrier(obj);
	objects.insert(objects.begin() + index, obj);
}

void UserVector::sort(std::function<bool(Object_*, Object_*)> sortF) {
	std::sort(objects.begin(), objects.end(), sortF);
}

void UserVector::removeAt(int index) {
	auto obj = objects.at(index);
	objects.erase(objects.begin() + index);
}

void UserVector::remove(Object_ * obj) {
	for (int i = 0; i < objects.size(); i++) {
		Object_* elem = objects.at(i);
		if (elem == obj) {
			removeAt(i);
			break;
		}
	}
}

void UserVector::push(Object_ * obj) {
	Heap::getInstance()->writeBarrier(this, obj);
	objects.insert(objects.begin(), obj);
}

Object_ * UserVector::top() {
	return objects.at(0);
}

Object_ * UserVector::back() {
	return objects.back();
}

void UserVector::pop() {
	objects.pop_back();
}

int UserVector::size() {
	return objects.size();
}

std::vector<Object_*> UserVector::getVirtualField() {
	return concatDynamicMembers(objects);
}
//---public method

//protected method---
void UserVector::lazyLoading() {
	setClass(Package::getClassOrLoad("api.coll.Vector"));
}
//---protected method
