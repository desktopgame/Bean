#include "Page.h"
#include <algorithm>
#include <assert.h>
#include "Heap.h"
#include "../Class.h"
#include "../Object_.h"

//public method---
Page::Page(int rank) {
	this->rank = rank;
	this->objects = std::vector<Object_*>();
}

Page::~Page() {
}

void Page::add(Object_ * obj) {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	if (obj == nullptr) {
		return;
	}
	Heap::getInstance()->enter();
	objects.push_back(obj);
	auto state = obj->getState();
	state->setProgress(GCProgress::Pending);
	state->setRank(this->rank);
	Heap::getInstance()->exit();
}

Object_* Page::get(int index) const {
	return objects.at(index);
}

void Page::removeAt(int index) {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	Object_* obj = objects.at(index);
//	obj->getState()->removeWeakReference(this);
	obj->getState()->setRank(this->rank - 1);
	objects.erase(objects.begin() + index);
}

void Page::remove(Object_ * obj) {
	removeImpl(obj, true);
}

int Page::size() const {
	return objects.size();
}

void Page::fix() {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	for (Object_* obj : objects) {
		obj->getState()->setRank(0);
	}
}

void Page::fix(PageSPtr prev) {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	for (Object_* obj : objects) {
		prev->add(obj);
	}
}

void Page::obj_markAll() {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	for (Object_* obj : this->objects) {
		obj->markTree();
	}
}

void Page::obj_clearAll() {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	for (Object_* obj : this->objects) {
		obj->getState()->setMarked(false);
	}
}

void Page::obj_paintAll(GCProgress progress) {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	for (Object_* obj : this->objects) {
		obj->getState()->setProgress(progress);
	}
}

std::vector<Object_*> Page::getObjects() const {
	return this->objects;
}
//---public method

//private method---
void Page::removeImpl(Object_ * obj, bool listenerRemove) {
	for (int i = 0; i < objects.size(); i++) {
		Object_* elem = objects.at(i);
		if (elem == obj) {
			if (listenerRemove) {
				removeAt(i);
			} else {
				objects.erase(objects.begin() + i);
			}
			break;
		}
	}
}
//---private method
