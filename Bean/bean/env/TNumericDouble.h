#pragma once
#ifndef BEAN_ENV_TNUMERICDOUBLE_H
#define BEAN_ENV_TNUMERICDOUBLE_H
#include "Boolean.h"
#include "Package.h"
#include "TNumeric.h"

//
//init
//

template<>
void TNumeric<double>::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Double"));
}

//
//cast
//

template<>
short TNumeric<double>::getCShort() {
	return value;
}

template<>
int TNumeric<double>::getCInt() {
	return value;
}

template<>
long TNumeric<double>::getCLong() {
	return value;
}

template<>
float TNumeric<double>::getCFloat() {
	return value;
}

template<>
double TNumeric<double>::getCDouble() {
	return value;
}

//
//eval with short
//

//double + short
template<>
Object_ * TNumeric<double>::addShort(PShort * right) {
	return new PInteger(right->getValue() + value);
}

//double - short
template<>
Object_ * TNumeric<double>::subShort(PShort * right) {
	return new PInteger(right->getValue() - value);
}

//double * short
template<>
Object_ * TNumeric<double>::mulShort(PShort * right) {
	return new PInteger(right->getValue() * value);
}

//double / short
template<>
Object_ * TNumeric<double>::divShort(PShort * right) {
	return new PInteger(right->getValue() / value);
}

//double % short
template<>
Object_ * TNumeric<double>::modShort(PShort * right) {
	return new PDouble(right->getValue() % (int)value);
}

//double == short
template<>
Object_ * TNumeric<double>::equalsShort(PShort * right) {
	return Boolean::get(value == right->getValue());
}

//double > short
template<>
Object_ * TNumeric<double>::biggestShort(PShort * right) {
	return Boolean::get(value > right->getValue());
}

//double >= short
template<>
Object_ * TNumeric<double>::e_biggestShort(PShort * right) {
	return Boolean::get(value >= right->getValue());
}

//double < short
template<>
Object_ * TNumeric<double>::smallestShort(PShort * right) {
	return Boolean::get(value < right->getValue());
}

//double <= short
template<>
Object_ * TNumeric<double>::e_smallestShort(PShort * right) {
	return Boolean::get(value <= right->getValue());
}


//
//eval with Int
//

//double + int
template<>
Object_* TNumeric<double>::addInt(PInteger* right) {
	return new PInteger(right->getValue() + value);
}

//double - int
template<>
Object_* TNumeric<double>::subInt(PInteger* right) {
	return new PInteger(right->getValue() - value);
}

//double * int
template<>
Object_* TNumeric<double>::mulInt(PInteger* right) {
	return new PInteger(right->getValue() * value);
}

//double / int
template<>
Object_* TNumeric<double>::divInt(PInteger* right) {
	return new PInteger((int)(right->getValue() / value));
}

//double % int
template<>
Object_* TNumeric<double>::modInt(PInteger* right) {
	return new PInteger((double)(right->getValue() % (long)value));
}

//double == int
template<>
Object_* TNumeric<double>::equalsInt(PInteger* right) {
	return Boolean::get(value == right->getValue());
}

//double > int
template<>
Object_* TNumeric<double>::biggestInt(PInteger* right) {
	return Boolean::get(value > right->getValue());
}

//double >= int
template<>
Object_* TNumeric<double>::e_biggestInt(PInteger* right) {
	return Boolean::get(value >= right->getValue());
}

//double < int
Object_* TNumeric<double>::smallestInt(PInteger* right) {
	return Boolean::get(value < right->getValue());
}

//double <= int
Object_* TNumeric<double>::e_smallestInt(PInteger* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}

//
//eval with long
//

//double + long
template<>
Object_* TNumeric<double>::addLong(PLong* right) {
	return new PLong(right->getValue() + value);
}

//double - long
template<>
Object_* TNumeric<double>::subLong(PLong* right) {
	return new PLong(right->getValue() - value);
}

//double * long
template<>
Object_* TNumeric<double>::mulLong(PLong* right) {
	return new PLong(right->getValue() * value);
}

//double / long
template<>
Object_* TNumeric<double>::divLong(PLong* right) {
	return new PLong((long)(right->getValue() / value));
}

//double % long
template<>
Object_* TNumeric<double>::modLong(PLong* right) {
	return new PLong((long)(right->getValue() % (long)value));
}

//double == long
template<>
Object_* TNumeric<double>::equalsLong(PLong* right) {
	return Boolean::get(value == right->getValue());
}

//double > long
template<>
Object_* TNumeric<double>::biggestLong(PLong* right) {
	return Boolean::get(value > right->getValue());
}

//double >= long
template<>
Object_* TNumeric<double>::e_biggestLong(PLong* right) {
	return Boolean::get(value >= right->getValue());
}

//double < long
Object_* TNumeric<double>::smallestLong(PLong* right) {
	return Boolean::get(value < right->getValue());
}

//double <= long
Object_* TNumeric<double>::e_smallestLong(PLong* right) {
	int v = getValue();
	return Boolean::get(v <= right->getValue());
}


//
//eval with float
//

//double + float
template<>
Object_* TNumeric<double>::addFloat(PFloat* right) {
	return new PFloat((float)right->getValue() + value);
}

//double - float
template<>
Object_* TNumeric<double>::subFloat(PFloat* right) {
	return new PFloat(right->getValue() - value);
}

//double * float
template<>
Object_* TNumeric<double>::mulFloat(PFloat* right) {
	return new PFloat(right->getValue() * value);
}

//double / float
template<>
Object_* TNumeric<double>::divFloat(PFloat* right) {
	return new PFloat((int)(right->getValue() / value));
}

//double % float
template<>
Object_* TNumeric<double>::modFloat(PFloat* right) {
	return new PFloat((float)((int)right->getValue() % (int)value));
}

//double == float
template<>
Object_* TNumeric<double>::equalsFloat(PFloat* right) {
	return Boolean::get((float)value == right->getValue());
}

//double > float
template<>
Object_* TNumeric<double>::biggestFloat(PFloat* right) {
	return Boolean::get((float)value > right->getValue());
}

//double >= float
template<>
Object_* TNumeric<double>::e_biggestFloat(PFloat* right) {
	return Boolean::get((float)value >= right->getValue());
}

//double < float
Object_* TNumeric<double>::smallestFloat(PFloat* right) {
	return Boolean::get((float)value < right->getValue());
}

//double <= float
Object_* TNumeric<double>::e_smallestFloat(PFloat* right) {
	return Boolean::get((float)value <= right->getValue());
}

//
//eval with double
//

//double + double
template<>
Object_ * TNumeric<double>::addDouble(PDouble * right) {
	return new PDouble(right->getValue() + value);
}

//double - double
template<>
Object_ * TNumeric<double>::subDouble(PDouble * right) {
	return new PDouble(right->getValue() - value);
}

//double * double
template<>
Object_ * TNumeric<double>::mulDouble(PDouble * right) {
	return new PDouble(right->getValue() * value);
}

//double / double
template<>
Object_ * TNumeric<double>::divDouble(PDouble * right) {
	return new PDouble(right->getValue() / value);
}

//double % double
template<>
Object_ * TNumeric<double>::modDouble(PDouble * right) {
	return new PDouble((double)((int)right -> getValue() % (int)value));
}

//double == double
template<>
Object_ * TNumeric<double>::equalsDouble(PDouble * right) {
	return Boolean::get(value == right->getValue());
}

//double > double
template<>
Object_ * TNumeric<double>::biggestDouble(PDouble * right) {
	return Boolean::get(value > right->getValue());
}

//double >= double
template<>
Object_ * TNumeric<double>::e_biggestDouble(PDouble * right) {
	return Boolean::get(value >= right->getValue());
}

//double < double
template<>
Object_ * TNumeric<double>::smallestDouble(PDouble * right) {
	return Boolean::get(value < right->getValue());
}

//double <= double
template<>
Object_ * TNumeric<double>::e_smallestDouble(PDouble * right) {
	return Boolean::get(value <= right->getValue());
}
#endif // !BEAN_ENV_TNUMERICDOUBLE_H
