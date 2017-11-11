#include "Enum.h"
#include "ClassLoader.h"
#include "Field.h"

int Enum::enumId = 0;

//public method---
Enum::Enum(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name)
 : Class(classLoader, super, name) {
	this->id = Enum::enumId++;
}

Enum::~Enum() {
}

bool Enum::isEnum() const {
	return true;
}

Object_ * Enum::findEnumItem(const std::string & name) {
	for (Field* field : getFields()) {
		if (field->getName() == name) {
			return field->getValue(nullptr);
		}
	}
	return nullptr;
}

bool Enum::containsEnumItem(Object_ * obj) {
	for (Field* field : getFields()) {
		if (field->getValue(nullptr) == obj) {
			return true;
		}
	}
	return false;
}

int Enum::getId() const {
	return this->id;
}
//---public method