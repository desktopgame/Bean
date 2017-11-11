#include "Null.h"
#include <iostream>
#include "Boolean.h"
#include "Package.h"

//public method---
Object_ * Null::clone() {
	return this;
}

Object_ * Null::add(Object_ * right) {
	return this;
}

Object_ * Null::sub(Object_ * right) {
	return this;
}

Object_ * Null::mul(Object_ * right) {
	return this;
}

Object_ * Null::div(Object_ * right) {
	return this;
}

Object_ * Null::mod(Object_ * right) {
	return this;
}

Object_ * Null::equals(Object_ * right) {
	return Boolean::get(this == right);
}

void Null::dump() {
	std::cout << "Null" << std::endl;
}

bool Null::isSingleton() {
	return true;
}

void Null::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Null"));
}
//---public method

//private method---
Null::Null() : Object_(nullptr) {
}

Null::~Null() {
}
//---private method
