#include "UserArray.h"
#include "../Boolean.h"
#include "../Null.h"
#include "../Object_.h"
#include "../Package.h"
#include "../gc/Heap.h"

//public method---
UserArray::UserArray()
	: Object_(nullptr) {
	setClass(Package::getClass("api.Array"));
	this->elems = std::vector<Object_*>();
}

UserArray::~UserArray() {
//	for (Object_* elem : elems) elem->clear();
}

void UserArray::alloc(int length) {
	elems.clear();
	for (int i = 0; i < length; i++) {
		elems.push_back(Null::getInstance());
	}
	this->length = length;
}

void UserArray::set(int index, Object_ * ref) {
	elems[index] = ref;
	Heap::getInstance()->writeBarrier(ref);
//	elems[index]->setValue(ref->getValue());
//	elems[index]->setSource(ref);
}

Object_ * const UserArray::get(int index) const {
	return elems.at(index);
}

int UserArray::getLength() {
	return length;
}

Object_ * UserArray::clone() {
	return nullptr;
}

std::vector<Object_*> UserArray::getVirtualField() {
	return concatDynamicMembers(elems);
}

UserArray * UserArray::asUserArray() {
	return this;
}
//---public method
