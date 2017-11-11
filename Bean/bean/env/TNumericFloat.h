#pragma once
#ifndef BEAN_ENV_TNUMERICFLOAT_H
#define BEAN_ENV_TNUMERICFLOAT_H
#include "TNumeric.h"

//
//init
//

template<>
void TNumeric<float>::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Float"));
}

//
//cast
//

template<>
short TNumeric<float>::getCShort() {
	return value;
}

template<>
int TNumeric<float>::getCInt() {
	return value;
}

template<>
long TNumeric<float>::getCLong() {
	return value;
}

template<>
float TNumeric<float>::getCFloat() {
	return value;
}

template<>
double TNumeric<float>::getCDouble() {
	return value;
}

//
//eval with short
//

//float + short
template<>
Object_ * TNumeric<float>::addShort(PShort * right) {
	return new PFloat(right->getValue() + value);
}

//float - short
template<>
Object_ * TNumeric<float>::subShort(PShort * right) {
	return new PFloat(right->getValue() - value);
}

//float * short
template<>
Object_ * TNumeric<float>::mulShort(PShort * right) {
	return new PFloat(right->getValue() * value);
}

//float / short
template<>
Object_ * TNumeric<float>::divShort(PShort * right) {
	return new PFloat(right->getValue() / value);
}

//float % short
template<>
Object_ * TNumeric<float>::modShort(PShort * right) {
	return new PFloat(right->getValue() % (int)value);
}

//float == short
template<>
Object_ * TNumeric<float>::equalsShort(PShort * right) {
	return Boolean::get(value == right->getValue());
}

//float > short
template<>
Object_ * TNumeric<float>::biggestShort(PShort * right) {
	return Boolean::get(value > right->getValue());
}

//float >= short
template<>
Object_ * TNumeric<float>::e_biggestShort(PShort * right) {
	return Boolean::get(value >= right->getValue());
}

//float < short
template<>
Object_ * TNumeric<float>::smallestShort(PShort * right) {
	return Boolean::get(value < right->getValue());
}

//float <= short
template<>
Object_ * TNumeric<float>::e_smallestShort(PShort * right) {
	return Boolean::get(value <= right->getValue());
}

//
//eval with int
//

//float + int
template<>
Object_* TNumeric<float>::addInt(PInteger* right) {
	return new PFloat(right->getValue() + value);
}

//float - int
template<>
Object_* TNumeric<float>::subInt(PInteger* right) {
	return new PFloat(right->getValue() - value);
}

//float * int
template<>
Object_* TNumeric<float>::mulInt(PInteger* right) {
	return new PFloat(right->getValue() * value);
}

//float / int
template<>
Object_* TNumeric<float>::divInt(PInteger* right) {
	return new PFloat(right->getValue() / value);
}

//float % int
template<>
Object_* TNumeric<float>::modInt(PInteger* right) {
	return new PFloat((right->getValue() % (int)value));
}

//float == int
template<>
Object_* TNumeric<float>::equalsInt(PInteger* right) {
	return Boolean::get(value == right->getValue());
}

//float > int
template<>
Object_* TNumeric<float>::biggestInt(PInteger* right) {
	return Boolean::get(value > right->getValue());
}

//float >= int
template<>
Object_* TNumeric<float>::e_biggestInt(PInteger* right) {
	return Boolean::get(value >= right->getValue());
}

//float < int
Object_* TNumeric<float>::smallestInt(PInteger* right) {
	return Boolean::get(value < right->getValue());
}

//float <= int
Object_* TNumeric<float>::e_smallestInt(PInteger* right) {
	return Boolean::get(value <= right->getValue());
}

//
//eval with long
//

//float + long
template<>
Object_* TNumeric<float>::addLong(PLong* right) {
	return new PLong(right->getValue() + value);
}

//float - long
template<>
Object_* TNumeric<float>::subLong(PLong* right) {
	return new PLong(right->getValue() - value);
}

//float * long
template<>
Object_* TNumeric<float>::mulLong(PLong* right) {
	return new PLong(right->getValue() * value);
}

//float / long
template<>
Object_* TNumeric<float>::divLong(PLong* right) {
	return new PLong((long)(right->getValue() / value));
}

//float % long
template<>
Object_* TNumeric<float>::modLong(PLong* right) {
	return new PLong((long)(right->getValue() % (long)value));
}

//float == long
template<>
Object_* TNumeric<float>::equalsLong(PLong* right) {
	return Boolean::get(value == right->getValue());
}

//float > long
template<>
Object_* TNumeric<float>::biggestLong(PLong* right) {
	return Boolean::get(value > right->getValue());
}

//float >= long
template<>
Object_* TNumeric<float>::e_biggestLong(PLong* right) {
	return Boolean::get(value >= right->getValue());
}

//float < long
Object_* TNumeric<float>::smallestLong(PLong* right) {
	return Boolean::get(value < right->getValue());
}

//float <= long
Object_* TNumeric<float>::e_smallestLong(PLong* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}

//
//eval with float
//

//float + float
template<>
Object_* TNumeric<float>::addFloat(PFloat* right) {
	return new PFloat(right->getValue() + value);
}

//float - float
template<>
Object_* TNumeric<float>::subFloat(PFloat* right) {
	return new PFloat(right->getValue() - value);
}

//float * float
template<>
Object_* TNumeric<float>::mulFloat(PFloat* right) {
	return new PFloat(right->getValue() * value);
}

//float / float
template<>
Object_* TNumeric<float>::divFloat(PFloat* right) {
	return new PFloat(right->getValue() / value);
}

//float % float
template<>
Object_* TNumeric<float>::modFloat(PFloat* right) {
	return new PFloat((int)right->getValue() % (int)value);
}

//float == float
template<>
Object_* TNumeric<float>::equalsFloat(PFloat* right) {
	return Boolean::get(value == right->getValue());
}

//float > float
template<>
Object_* TNumeric<float>::biggestFloat(PFloat* right) {
	return Boolean::get(value > right->getValue());
}

//float >= float
template<>
Object_* TNumeric<float>::e_biggestFloat(PFloat* right) {
	return Boolean::get(value >= right->getValue());
}

//float < float
Object_* TNumeric<float>::smallestFloat(PFloat* right) {
	return Boolean::get(value < right->getValue());
}

//float <= float
Object_* TNumeric<float>::e_smallestFloat(PFloat* right) {
	return Boolean::get(value <= right->getValue());
}
#endif // !BEAN_ENV_TNUMERICFLOAT_H
