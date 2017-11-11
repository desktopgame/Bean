#include "EnumItem.h"
#include "Object_.h"

//public method---
EnumItem::EnumItem(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, int id, Object_* value)
 : Class(classLoader, super, name, true) {
	this->id = id;
	this->value = value;
	value->getState()->addStrongReference(this);
}

int EnumItem::getId() const {
	return this->id;
}

Object_ * EnumItem::getValue() const {
	return value;
}

EnumItem::~EnumItem() {
	value->getState()->removeStrongReference(this);
}
//---public method