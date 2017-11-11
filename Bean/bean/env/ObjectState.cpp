#include "ObjectState.h"
#include "Class.h"
#include "Object_.h"
#include "WeakReference.h"
#include "gc/Block.h"
#include "gc/Heap.h"
#include "user/UserArray.h"

//public method---
ObjectState::ObjectState(Object_* parent) {
	this->parent = parent;
	this->marked = false;
	this->notify = false;
	this->rank = 0;
	this->mutator = 0;
	this->age = 0;
	this->progress = GCProgress::NotSearch;
	this->strongReferences = std::vector<Reference*>();
	this->weakReferences = std::vector<WeakReference*>();
}

ObjectState::~ObjectState() {
}

void ObjectState::addStrongReference(Reference * ref) {
	strongReferences.emplace_back(ref);
}

void ObjectState::removeStrongReference(Reference * ref, bool isDelete) {
	for (int i = 0; i < strongReferences.size(); i++) {
		Reference* elemRef = strongReferences.at(i);
		if (ref == elemRef) {
			strongReferences.erase(strongReferences.begin() + i);
			break;
		}
	}
	if (isDelete &&
		(strongReferences.empty() &&
		 !parent->isSingleton())) {
		Heap::deleteItem(parent);
		Heap::getInstance()->remove(parent);
		parent->die();
	}
}

void ObjectState::removeStrongReference(Reference * ref) {
	removeStrongReference(ref, true);
}

int ObjectState::getStrongReferenceCount() const {
	return this->strongReferences.size();
}

void ObjectState::addWeakReference(WeakReference * wRef) {
	this->weakReferences.emplace_back(wRef);
}

void ObjectState::removeWeakReference(WeakReference * wRef) {
	if (notify) {
		return;
	}
	for (int i = 0; i < weakReferences.size(); i++) {
		WeakReference* elemRef = weakReferences.at(i);
		if (wRef == elemRef) {
			weakReferences.erase(weakReferences.begin() + i);
			break;
		}
	}
}

int ObjectState::getWeakReferenceCount() const {
	return weakReferences.size();
}

void ObjectState::setMarked(bool bMarked) {
	this->marked = bMarked;
}

bool ObjectState::isMarked() const {
	return this->marked;
}

void ObjectState::setRank(int rank) {
	this->rank = rank;
}

int ObjectState::getRank() const {
	return this->rank;
}

void ObjectState::setAge(int age) {
	this->age = age;
}

int ObjectState::getAge() const {
	return this->age;
}

void ObjectState::setProgress(GCProgress progress) {
	this->progress = progress;
}

GCProgress ObjectState::getProgress() const {
	return this->progress;
}

std::string ObjectState::getProgressStr() const {
	switch (getProgress()) {
		case GCProgress::NotSearch: return "NotSearch";
		case GCProgress::SearchNow: return "SearchNow";
		case GCProgress::SearchComp: return "SearchComp";
		case GCProgress::Pending: return "Pending";
		default:
			break;
	}
	return "null";
}

void ObjectState::onDelete(Object_ * obj) {
	this->notify = true;
	for (WeakReference* wRef : weakReferences) {
		wRef->onDelete(obj);
	}
	weakReferences.clear();
	this->notify = false;
}
//---public method
