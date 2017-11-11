#pragma once
#ifndef BEAN_ENV_TNUMERICSHORT_H
#define BEAN_ENV_TNUMERICSHORT_H
#include "TNumeric.h"

//
//init
//

template<>
void TNumeric<short>::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Short"));
}

//
//cast
//

template<>
short TNumeric<short>::getCShort() {
	return value;
}

template<>
int TNumeric<short>::getCInt() {
	return value;
}

template<>
long TNumeric<short>::getCLong() {
	return value;
}

template<>
float TNumeric<short>::getCFloat() {
	return value;
}

template<>
double TNumeric<short>::getCDouble() {
	return value;
}

//
//eval with short
//

//short + short
template<>
Object_ * TNumeric<short>::addShort(PShort * right) {
	return new PInteger(right->getValue() + value);
}

//short - short
template<>
Object_ * TNumeric<short>::subShort(PShort * right) {
	return new PInteger(right->getValue() - value);
}

//short * short
template<>
Object_ * TNumeric<short>::mulShort(PShort * right) {
	return new PInteger(right->getValue() * value);
}

//short / short
template<>
Object_ * TNumeric<short>::divShort(PShort * right) {
	return new PInteger(right->getValue() / value);
}

//short % short
template<>
Object_ * TNumeric<short>::modShort(PShort * right) {
	return new PInteger(right->getValue() % value);
}

//short == short
template<>
Object_ * TNumeric<short>::equalsShort(PShort * right) {
	return Boolean::get(value == right->getValue());
}

//short > short
template<>
Object_ * TNumeric<short>::biggestShort(PShort * right) {
	return Boolean::get(value > right->getValue());
}

//short >= short
template<>
Object_ * TNumeric<short>::e_biggestShort(PShort * right) {
	return Boolean::get(value >= right->getValue());
}

//short < short
template<>
Object_ * TNumeric<short>::smallestShort(PShort * right) {
	return Boolean::get(value < right->getValue());
}

//short <= short
template<>
Object_ * TNumeric<short>::e_smallestShort(PShort * right) {
	return Boolean::get(value <= right->getValue());
}

//
//eval with int
//

//short + int
template<>
Object_* TNumeric<short>::addInt(PInteger* right) {
	return new PInteger(right->getValue() + value);
}

//short - int
template<>
Object_* TNumeric<short>::subInt(PInteger* right) {
	return new PInteger(right->getValue() - value);
}

//short * int
template<>
Object_* TNumeric<short>::mulInt(PInteger* right) {
	return new PInteger(right->getValue() * value);
}

//short / int
template<>
Object_* TNumeric<short>::divInt(PInteger* right) {
	return new PInteger(right->getValue() / value);
}

//short % int
template<>
Object_* TNumeric<short>::modInt(PInteger* right) {
	return new PInteger(right->getValue() % value);
}

//short == int
template<>
Object_* TNumeric<short>::equalsInt(PInteger* right) {
	return Boolean::get(value == right->getValue());
}

//short > int
template<>
Object_* TNumeric<short>::biggestInt(PInteger* right) {
	return Boolean::get(value > right->getValue());
}

//short >= int
template<>
Object_* TNumeric<short>::e_biggestInt(PInteger* right) {
	return Boolean::get(value >= right->getValue());
}

//short < int
Object_* TNumeric<short>::smallestInt(PInteger* right) {
	return Boolean::get(value < right->getValue());
}

//short <= int
Object_* TNumeric<short>::e_smallestInt(PInteger* right) {
	return Boolean::get(value <= right->getValue());
}

//
//eval with long
//

//short + long
template<>
Object_* TNumeric<short>::addLong(PLong* right) {
	return new PLong(right->getValue() + value);
}

//short - long
template<>
Object_* TNumeric<short>::subLong(PLong* right) {
	return new PLong(right->getValue() - value);
}

//short * long
template<>
Object_* TNumeric<short>::mulLong(PLong* right) {
	return new PLong(right->getValue() * value);
}

//short / long
template<>
Object_* TNumeric<short>::divLong(PLong* right) {
	return new PLong((long)(right->getValue() / value));
}

//short % long
template<>
Object_* TNumeric<short>::modLong(PLong* right) {
	return new PLong((long)(right->getValue() % value));
}

//short == long
template<>
Object_* TNumeric<short>::equalsLong(PLong* right) {
	return Boolean::get(value == right->getValue());
}

//short > long
template<>
Object_* TNumeric<short>::biggestLong(PLong* right) {
	return Boolean::get(value > right->getValue());
}

//short >= long
template<>
Object_* TNumeric<short>::e_biggestLong(PLong* right) {
	return Boolean::get(value >= right->getValue());
}

//short < long
Object_* TNumeric<short>::smallestLong(PLong* right) {
	return Boolean::get(value < right->getValue());
}

//short <= long
Object_* TNumeric<short>::e_smallestLong(PLong* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}

//
//eval with float
//

//short + float
template<>
Object_* TNumeric<short>::addFloat(PFloat* right) {
	return new PFloat(right->getValue() + value);
}

//short - float
template<>
Object_* TNumeric<short>::subFloat(PFloat* right) {
	return new PFloat(right->getValue() - value);
}

//short * float
template<>
Object_* TNumeric<short>::mulFloat(PFloat* right) {
	return new PFloat(right->getValue() * value);
}

//short / float
template<>
Object_* TNumeric<short>::divFloat(PFloat* right) {
	return new PFloat(right->getValue() / value);
}

//short % float
template<>
Object_* TNumeric<short>::modFloat(PFloat* right) {
	return new PFloat((short)right->getValue() % value);
}

//short == float
template<>
Object_* TNumeric<short>::equalsFloat(PFloat* right) {
	return Boolean::get(value == right->getValue());
}

//short > float
template<>
Object_* TNumeric<short>::biggestFloat(PFloat* right) {
	return Boolean::get(value > right->getValue());
}

//short >= float
template<>
Object_* TNumeric<short>::e_biggestFloat(PFloat* right) {
	return Boolean::get(value >= right->getValue());
}

//short < float
Object_* TNumeric<short>::smallestFloat(PFloat* right) {
	return Boolean::get(value < right->getValue());
}

//short <= float
Object_* TNumeric<short>::e_smallestFloat(PFloat* right) {
	return Boolean::get(value <= right->getValue());
}

//
//eval with double
//

//short + double
template<>
Object_ * TNumeric<short>::addDouble(PDouble * right) {
	return new PDouble(right->getValue() + value);
}

//short - double
template<>
Object_ * TNumeric<short>::subDouble(PDouble * right) {
	return new PDouble(right->getValue() - value);
}

//short * double
template<>
Object_ * TNumeric<short>::mulDouble(PDouble * right) {
	return new PDouble(right->getValue() * value);
}

//short / double
template<>
Object_ * TNumeric<short>::divDouble(PDouble * right) {
	return new PDouble(right->getValue() / value);
}

//short % double
template<>
Object_ * TNumeric<short>::modDouble(PDouble * right) {
	return new PDouble((short)right->getValue() % value);
}

//short == double
template<>
Object_ * TNumeric<short>::equalsDouble(PDouble * right) {
	return Boolean::get(value == right->getValue());
}

//short > double
template<>
Object_ * TNumeric<short>::biggestDouble(PDouble * right) {
	return Boolean::get(value > right->getValue());
}

//short >= double
template<>
Object_ * TNumeric<short>::e_biggestDouble(PDouble * right) {
	return Boolean::get(value >= right->getValue());
}

//short < double
template<>
Object_ * TNumeric<short>::smallestDouble(PDouble * right) {
	return Boolean::get(value < right->getValue());
}

//short <= double
template<>
Object_ * TNumeric<short>::e_smallestDouble(PDouble * right) {
	return Boolean::get(value <= right->getValue());
}
#endif // !BEAN_ENV_TNUMERICSHORT_H
