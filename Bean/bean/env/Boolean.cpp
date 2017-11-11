#include "Boolean.h"
#include <iostream>
#include "Null.h"
#include "Package.h"

//public method---
Boolean * Boolean::get(bool v) {
	return v ? getTrue() : getFalse();
}

Boolean * Boolean:: or (Boolean * left, Boolean * right) {
	return or(left->of(), right->of());
}

Boolean * Boolean:: or (bool left, bool right) {
	return get(left || right);
}

Boolean * Boolean:: and (Boolean * left, Boolean * right) {
	return and(left->of(), right->of());
}

Boolean * Boolean:: and (bool left, bool right) {
	return get(left && right);
}

bool Boolean::isSingleton() {
	return true;
}

void Boolean::dump() {
	std::cout << "Boolean(" << a << "): ";
	dumpAttrLn();
}

Boolean * Boolean::asBoolean() {
	return this;
}

Object_ * Boolean::clone() {
	return get(a);
}


Object_ * Boolean::equals(Object_ * right) {
	Boolean* bRight = right->asBoolean();
	if (bRight == nullptr) {
		return Boolean::getFalse();
	}
	return get(this->a == bRight->a);
}
//---public method

//protected method---
void Boolean::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Boolean"));
}
//---protected method

//private method---
Boolean::Boolean(bool a) : Object_(nullptr) {
	this->a = a;
	lazyLoading();
}

Boolean::~Boolean() {
}
//---private method
