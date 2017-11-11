#pragma once
#ifndef BEAN_ENV_TNUMERICDEFAULTS_H
#define BEAN_ENV_TNUMERICDEFAULTS_H
#include "TNumeric.h"

//
//init
//

template<typename T>
void TNumeric<T>::lazyLoading() {
}

//
//cast
//

template<typename T>
short TNumeric<T>::getCShort() {
	return 0;
}

template<typename T>
int TNumeric<T>::getCInt() {
	return 0;
}

template<typename T>
long TNumeric<T>::getCLong() {
	return 0L;
}

template<typename T>
float TNumeric<T>::getCFloat() {
	return 0.0f;
}

template<typename T>
double TNumeric<T>::getCDouble() {
	return 0;
}

template<typename T>
std::string TNumeric<T>::toString() {
	return std::to_string(getValue());
}

template<typename T>
String* TNumeric<T>::toString(Object_ * o) {
	//FIXME:toStringがオーバーライドされている場合
	int i = Heap::getInstance()->getCurrentSize();
	Object_* retRef = execute("toString");
	String* s = retRef->asString();
	String* str = o->asString();
	return String::allocString(*s->getCString() + *str->getCString());
}

template<typename T>
T TNumeric<T>::getValue() {
	return value;
}

//
//eval
//

template<typename T>
Object_ * TNumeric<T>::clone() {
	return new TNumeric<T>(value);
}

template<typename T>
Object_ * TNumeric<T>::add(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::sub(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::mul(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::div(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::mod(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::equals(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::biggest(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_biggest(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::smallest(Object_ * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_smallest(Object_ * right) {
	return nullptr;
}

template<typename T>
void TNumeric<T>::increment() {
	this->value++;
}

template<typename T>
void TNumeric<T>::decrement() {
	this->value--;
}

//
//eval with short
//

template<typename T>
Object_ * TNumeric<T>::addShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::subShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::mulShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::divShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::modShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::equalsShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::biggestShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_biggestShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::smallestShort(PShort * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_smallestShort(PShort * right) {
	return nullptr;
}

//
//eval with int
//

template<typename T>
Object_ * TNumeric<T>::addInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::subInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::mulInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::divInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::modInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::equalsInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::biggestInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_biggestInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::smallestInt(PInteger * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_smallestInt(PInteger * right) {
	return nullptr;
}

//
//eval long
//

template<typename T>
Object_ * TNumeric<T>::addLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::subLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::mulLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::divLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::modLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::equalsLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::biggestLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_biggestLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::smallestLong(PLong * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_smallestLong(PLong * right) {
	return nullptr;
}

//
//eval float
//

template<typename T>
Object_ * TNumeric<T>::addFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::subFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::mulFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::divFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::modFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::equalsFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::biggestFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_biggestFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::smallestFloat(PFloat * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_smallestFloat(PFloat * right) {
	return nullptr;
}

//
//eval double
//

template<typename T>
Object_ * TNumeric<T>::addDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::subDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::mulDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::divDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::modDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::equalsDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::biggestDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_biggestDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::smallestDouble(PDouble * right) {
	return nullptr;
}

template<typename T>
Object_ * TNumeric<T>::e_smallestDouble(PDouble * right) {
	return nullptr;
}

//helper---
template<typename T>
Object_ * TNumeric<T>::cast(Object_ * right, std::function<Object_*(Numeric*)> f) {
	Numeric* n = right->asNumeric();
	if (n == nullptr) {
		return nullptr;
	}
	return f(n);
}

template<typename T>
Object_* TNumeric<T>::this_cast(Object_ * right, std::function<Object_*(Numeric*, TNumeric<T>*)> f) {
	Numeric* n = right->asNumeric();
	if (n == nullptr) {
		//	return nullptr;
	}
	TNumeric* self = const_cast<TNumeric<T>*>(this);
	Heap* heap = Heap::getInstance();
	heap->lock();
	Object_* ret = f(n, self);
	heap->unlock();
	return ret;
}
//---helper
#endif // !BEAN_ENV_TNUMERICDEFAULTS_H
