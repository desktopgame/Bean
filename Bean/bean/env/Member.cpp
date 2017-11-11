#include "Member.h"
#include "Class.h"

//public method---
Member::Member(ClassSPtr classz, Modifier modifier, const std::string& name) {
	this->classz = std::weak_ptr<Class>(classz);
	this->modifier = modifier;
	this->name = name;
}

Member::~Member() {
}

ClassWPtr const Member::getClass() const {
	return this->classz;
}

Modifier Member::getModifier() const {
	return this->modifier;
}

std::string Member::getName() const {
	return this->name;
}
//---public method