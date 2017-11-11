#include "Delegate.h"

//public method---
Delegate::Delegate() {
	this->dynamicMethod = false;
}

Delegate::~Delegate() {
}

std::vector<Object_*> Delegate::getVirtualField(ClassLoaderSPtr cll) {
	return std::vector<Object_*>();
}

void Delegate::setDynamicMethod(bool b) {
	this->dynamicMethod = b;
}

bool Delegate::isDynamicMethod() {
	return this->dynamicMethod;
}
//---public method