#pragma once
#ifndef BEAN_ENV_TNUMERICLONG_H
#define BEAN_ENV_TNUMERICLONG_H
#include "TNumeric.h"

//
//init
//

template<>
void TNumeric<long>::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Long"));
}

//
//cast
//

template<>
short TNumeric<long>::getCShort() {
	return value;
}

template<>
int TNumeric<long>::getCInt() {
	return value;
}

template<>
long TNumeric<long>::getCLong() {
	return value;
}

template<>
float TNumeric<long>::getCFloat() {
	return value;
}

template<>
double TNumeric<long>::getCDouble() {
	return value;
}

//
//eval with short
//

//long + short
template<>
Object_ * TNumeric<long>::addShort(PShort * right) {
	return new PLong(right->getValue() + value);
}

//long - short
template<>
Object_ * TNumeric<long>::subShort(PShort * right) {
	return new PLong( right->getValue() - value);
}

//long * short
template<>
Object_ * TNumeric<long>::mulShort(PShort * right) {
	return new PLong(right->getValue() * value);
}

//long / short
template<>
Object_ * TNumeric<long>::divShort(PShort * right) {
	return new PLong(right->getValue() / value);
}

//long % short
template<>
Object_ * TNumeric<long>::modShort(PShort * right) {
	return new PLong(right->getValue() % value);
}

//long == short
template<>
Object_ * TNumeric<long>::equalsShort(PShort * right) {
	return Boolean::get(value == right->getValue());
}

//long > short
template<>
Object_ * TNumeric<long>::biggestShort(PShort * right) {
	return Boolean::get(value > right->getValue());
}

//long >= short
template<>
Object_ * TNumeric<long>::e_biggestShort(PShort * right) {
	return Boolean::get(value >= right->getValue());
}

//long < short
template<>
Object_ * TNumeric<long>::smallestShort(PShort * right) {
	return Boolean::get(value < right->getValue());
}

//long <= short
template<>
Object_ * TNumeric<long>::e_smallestShort(PShort * right) {
	return Boolean::get(value <= right->getValue());
}


//
//eval with Int
//

//long + int
template<>
Object_* TNumeric<long>::addInt(PInteger* right) {
	return new PLong(right->getValue() + value);
}

//long - int
template<>
Object_* TNumeric<long>::subInt(PInteger* right) {
	return new PLong(right->getValue() - value);
}

//long * int
template<>
Object_* TNumeric<long>::mulInt(PInteger* right) {
	return new PLong(right->getValue() * value);
}

//long / int
template<>
Object_* TNumeric<long>::divInt(PInteger* right) {
	return new PLong((int)(right->getValue() / value));
}

//long % int
template<>
Object_* TNumeric<long>::modInt(PInteger* right) {
	return new PLong((int)(right->getValue() % value));
}

//long == int
template<>
Object_* TNumeric<long>::equalsInt(PInteger* right) {
	return Boolean::get(value == right->getValue());
}

//long > int
template<>
Object_* TNumeric<long>::biggestInt(PInteger* right) {
	return Boolean::get(value > right->getValue());
}

//long >= int
template<>
Object_* TNumeric<long>::e_biggestInt(PInteger* right) {
	return Boolean::get(value >= right->getValue());
}

//long < int
Object_* TNumeric<long>::smallestInt(PInteger* right) {
	return Boolean::get(value < right->getValue());
}

//long <= int
Object_* TNumeric<long>::e_smallestInt(PInteger* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}

//
//eval with long
//

//long + long
template<>
Object_* TNumeric<long>::addLong(PLong* right) {
	return new PLong(right->getValue() + value);
}

//long - long
template<>
Object_* TNumeric<long>::subLong(PLong* right) {
	return new PLong(right->getValue() - value);
}

//long * long
template<>
Object_* TNumeric<long>::mulLong(PLong* right) {
	return new PLong(right->getValue() * value);
}

//long / long
template<>
Object_* TNumeric<long>::divLong(PLong* right) {
	return new PLong((long)(right->getValue() / value));
}

//long % long
template<>
Object_* TNumeric<long>::modLong(PLong* right) {
	return new PLong((long)(right->getValue() % value));
}

//long == long
template<>
Object_* TNumeric<long>::equalsLong(PLong* right) {
	return Boolean::get(value == right->getValue());
}

//long > long
template<>
Object_* TNumeric<long>::biggestLong(PLong* right) {
	return Boolean::get(value > right->getValue());
}

//long >= long
template<>
Object_* TNumeric<long>::e_biggestLong(PLong* right) {
	return Boolean::get(value >= right->getValue());
}

//long < long
Object_* TNumeric<long>::smallestLong(PLong* right) {
	return Boolean::get(value < right->getValue());
}

//long <= long
Object_* TNumeric<long>::e_smallestLong(PLong* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}


//
//eval with float
//

//long + float
template<>
Object_* TNumeric<long>::addFloat(PFloat* right) {
	return new PLong((float)right->getValue() + value);
}

//long - float
template<>
Object_* TNumeric<long>::subFloat(PFloat* right) {
	return new PLong(right->getValue() - value);
}

//long * float
template<>
Object_* TNumeric<long>::mulFloat(PFloat* right) {
	return new PLong(right->getValue() * value);
}

//long / float
template<>
Object_* TNumeric<long>::divFloat(PFloat* right) {
	return new PLong((int)(right->getValue() / value));
}

//long % float
template<>
Object_* TNumeric<long>::modFloat(PFloat* right) {
	return new PLong((float)((int)right->getValue() % value));
}

//long == float
template<>
Object_* TNumeric<long>::equalsFloat(PFloat* right) {
	return Boolean::get((float)value == right->getValue());
}

//long > float
template<>
Object_* TNumeric<long>::biggestFloat(PFloat* right) {
	return Boolean::get((float)value > right->getValue());
}

//long >= float
template<>
Object_* TNumeric<long>::e_biggestFloat(PFloat* right) {
	return Boolean::get((float)value >= right->getValue());
}

//long < float
Object_* TNumeric<long>::smallestFloat(PFloat* right) {
	return Boolean::get((float)value < right->getValue());
}

//long <= float
Object_* TNumeric<long>::e_smallestFloat(PFloat* right) {
	return Boolean::get((float)value <= right->getValue());
}

//
//eval with double
//

//long + double
template<>
Object_ * TNumeric<long>::addDouble(PDouble * right) {
	return new PDouble(right->getValue() + value);
}

//long - double
template<>
Object_ * TNumeric<long>::subDouble(PDouble * right) {
	return new PDouble(right->getValue() - value);
}

//long * double
template<>
Object_ * TNumeric<long>::mulDouble(PDouble * right) {
	return new PDouble(right->getValue() * value);
}

//long / double
template<>
Object_ * TNumeric<long>::divDouble(PDouble * right) {
	return new PDouble(right->getValue() / value);
}

//long % double
template<>
Object_ * TNumeric<long>::modDouble(PDouble * right) {
	return new PDouble((int)right->getValue() % value);
}

//long == double
template<>
Object_ * TNumeric<long>::equalsDouble(PDouble * right) {
	return Boolean::get(value == right->getValue());
}

//long > double
template<>
Object_ * TNumeric<long>::biggestDouble(PDouble * right) {
	return Boolean::get(value > right->getValue());
}

//long >= double
template<>
Object_ * TNumeric<long>::e_biggestDouble(PDouble * right) {
	return Boolean::get(value >= right->getValue());
}

//long < double
template<>
Object_ * TNumeric<long>::smallestDouble(PDouble * right) {
	return Boolean::get(value < right->getValue());
}

//long <= double
template<>
Object_ * TNumeric<long>::e_smallestDouble(PDouble * right) {
	return Boolean::get(value <= right->getValue());
}
#endif // !BEAN_ENV_TNUMERICLONG_H
