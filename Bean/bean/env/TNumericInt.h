#pragma once
#ifndef BEAN_ENV_TNUMERICINT_H
#define BEAN_ENV_TNUMERICINT_H
#include "TNumeric.h"

//
//init
//

template<>
void TNumeric<int>::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Integer"));
}

//
//cast
//

template<>
short TNumeric<int>::getCShort() {
	return value;
}

template<>
int TNumeric<int>::getCInt() {
	return value;
}

template<>
long TNumeric<int>::getCLong() {
	return value;
}

template<>
float TNumeric<int>::getCFloat() {
	return value;
}

template<>
double TNumeric<int>::getCDouble() {
	return value;
}

//
//eval with short
//

//int + short
template<>
Object_ * TNumeric<int>::addShort(PShort * right) {
	return new PInteger(right->getValue() + value);
}

//int - short
template<>
Object_ * TNumeric<int>::subShort(PShort * right) {
	return new PInteger(right->getValue() - value);
}

//int * short
template<>
Object_ * TNumeric<int>::mulShort(PShort * right) {
	return new PInteger(right->getValue() * value);
}

//int / short
template<>
Object_ * TNumeric<int>::divShort(PShort * right) {
	return new PInteger(right->getValue() / value);
}

//int % short
template<>
Object_ * TNumeric<int>::modShort(PShort * right) {
	return new PInteger(right->getValue() % value);
}

//int == short
template<>
Object_ * TNumeric<int>::equalsShort(PShort * right) {
	return Boolean::get(value == right->getValue());
}

//int > short
template<>
Object_ * TNumeric<int>::biggestShort(PShort * right) {
	return Boolean::get(value > right->getValue());
}

//int >= short
template<>
Object_ * TNumeric<int>::e_biggestShort(PShort * right) {
	return Boolean::get(value >= right->getValue());
}

//int < short
template<>
Object_ * TNumeric<int>::smallestShort(PShort * right) {
	return Boolean::get(value < right->getValue());
}

//int <= short
template<>
Object_ * TNumeric<int>::e_smallestShort(PShort * right) {
	return Boolean::get(value <= right->getValue());
}


//
//eval with Int
//

//int + int
template<>
Object_* TNumeric<int>::addInt(PInteger* right) {
	return new PInteger(right->getValue() + value);
}

//int - int
template<>
Object_* TNumeric<int>::subInt(PInteger* right) {
	return new PInteger(right->getValue() - value);
}

//int * int
template<>
Object_* TNumeric<int>::mulInt(PInteger* right) {
	return new PInteger(right->getValue() * value);
}

//int / int
template<>
Object_* TNumeric<int>::divInt(PInteger* right) {
	return new PInteger((int)(right->getValue() / value));
}

//int % int
template<>
Object_* TNumeric<int>::modInt(PInteger* right) {
	return new PInteger((int)(right->getValue() % value));
}

//int == int
template<>
Object_* TNumeric<int>::equalsInt(PInteger* right) {
	return Boolean::get(value == right->getValue());
}

//int > int
template<>
Object_* TNumeric<int>::biggestInt(PInteger* right) {
	return Boolean::get(value > right->getValue());
}

//int >= int
template<>
Object_* TNumeric<int>::e_biggestInt(PInteger* right) {
	return Boolean::get(value >= right->getValue());
}

//int < int
Object_* TNumeric<int>::smallestInt(PInteger* right) {
	return Boolean::get(value < right->getValue());
}

//int <= int
Object_* TNumeric<int>::e_smallestInt(PInteger* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}

//
//eval with long
//

//int + long
template<>
Object_* TNumeric<int>::addLong(PLong* right) {
	return new PLong(right->getValue() + value);
}

//int - long
template<>
Object_* TNumeric<int>::subLong(PLong* right) {
	return new PLong(right->getValue() - value);
}

//int * long
template<>
Object_* TNumeric<int>::mulLong(PLong* right) {
	return new PLong(right->getValue() * value);
}

//int / long
template<>
Object_* TNumeric<int>::divLong(PLong* right) {
	return new PLong((long)(right->getValue() / value));
}

//int % long
template<>
Object_* TNumeric<int>::modLong(PLong* right) {
	return new PLong((long)(right->getValue() % value));
}

//int == long
template<>
Object_* TNumeric<int>::equalsLong(PLong* right) {
	return Boolean::get(value == right->getValue());
}

//int > long
template<>
Object_* TNumeric<int>::biggestLong(PLong* right) {
	return Boolean::get(value > right->getValue());
}

//int >= long
template<>
Object_* TNumeric<int>::e_biggestLong(PLong* right) {
	return Boolean::get(value >= right->getValue());
}

//int < long
Object_* TNumeric<int>::smallestLong(PLong* right) {
	return Boolean::get(value < right->getValue());
}

//int <= long
Object_* TNumeric<int>::e_smallestLong(PLong* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}


//
//eval with float
//

//int + float
template<>
Object_* TNumeric<int>::addFloat(PFloat* right) {
	return new PFloat((float)right->getValue() + value);
}

//int - float
template<>
Object_* TNumeric<int>::subFloat(PFloat* right) {
	return new PFloat(right->getValue() - value);
}

//int * float
template<>
Object_* TNumeric<int>::mulFloat(PFloat* right) {
	return new PFloat(right->getValue() * value);
}

//int / float
template<>
Object_* TNumeric<int>::divFloat(PFloat* right) {
	return new PFloat((int)(right->getValue() / value));
}

//int % float
template<>
Object_* TNumeric<int>::modFloat(PFloat* right) {
	return new PFloat((float)((int)right->getValue() % value));
}

//int == float
template<>
Object_* TNumeric<int>::equalsFloat(PFloat* right) {
	return Boolean::get((float)value == right->getValue());
}

//int > float
template<>
Object_* TNumeric<int>::biggestFloat(PFloat* right) {
	return Boolean::get((float)value > right->getValue());
}

//int >= float
template<>
Object_* TNumeric<int>::e_biggestFloat(PFloat* right) {
	return Boolean::get((float)value >= right->getValue());
}

//int < float
Object_* TNumeric<int>::smallestFloat(PFloat* right) {
	return Boolean::get((float)value < right->getValue());
}

//int <= float
Object_* TNumeric<int>::e_smallestFloat(PFloat* right) {
	return Boolean::get((float)value <= right->getValue());
}

//
//eval with double
//

//int + double
template<>
Object_ * TNumeric<int>::addDouble(PDouble * right) {
	return new PDouble(right->getValue() + value);
}

//int - double
template<>
Object_ * TNumeric<int>::subDouble(PDouble * right) {
	return new PDouble(right->getValue() - value);
}

//int * double
template<>
Object_ * TNumeric<int>::mulDouble(PDouble * right) {
	return new PDouble(right->getValue() * value);
}

//int / double
template<>
Object_ * TNumeric<int>::divDouble(PDouble * right) {
	return new PDouble(right->getValue() / value);
}

//int % double
template<>
Object_ * TNumeric<int>::modDouble(PDouble * right) {
	return new PDouble((int)right->getValue() % value);
}

//int == double
template<>
Object_ * TNumeric<int>::equalsDouble(PDouble * right) {
	return Boolean::get(value == right->getValue());
}

//int > double
template<>
Object_ * TNumeric<int>::biggestDouble(PDouble * right) {
	return Boolean::get(value > right->getValue());
}

//int >= double
template<>
Object_ * TNumeric<int>::e_biggestDouble(PDouble * right) {
	return Boolean::get(value >= right->getValue());
}

//int < double
template<>
Object_ * TNumeric<int>::smallestDouble(PDouble * right) {
	return Boolean::get(value < right->getValue());
}

//int <= double
template<>
Object_ * TNumeric<int>::e_smallestDouble(PDouble * right) {
	return Boolean::get(value <= right->getValue());
}
#endif // !BEAN_ENV_TNUMERICINT_H
