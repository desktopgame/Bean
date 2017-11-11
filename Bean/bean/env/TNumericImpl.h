#pragma once
#ifndef BEAN_ENV_TNUMERICIMPL_H
#define BEAN_ENV_TNUMERICIMPL_H
//#include "TNumeric.h"
#include <iostream>
#include "Boolean.h"
#include "Numeric.h"
#include "Package.h"
#include "String.h"
#include "TNumeric.h"
#include "gc/Heap.h"

template<typename T>
TNumeric<T>::TNumeric(T value) : Numeric(nullptr) {
	this->value = value;
	typespec();
	//lazyLoading();
}

template<typename T>
TNumeric<T>::~TNumeric() {
}

template<typename T>
void TNumeric<T>::typespec() {
}

template<>
void TNumeric<short>::typespec() {
	setClass(Package::getClassOrLoad("api.Short"));
}

template<>
void TNumeric<int>::typespec() {
	setClass(Package::getClassOrLoad("api.Integer"));
}

template<>
void TNumeric<long>::typespec() {
	setClass(Package::getClassOrLoad("api.Long"));
}

template<>
void TNumeric<float>::typespec() {
	setClass(Package::getClassOrLoad("api.Float"));
}

template<>
void TNumeric<double>::typespec() {
	setClass(Package::getClassOrLoad("api.Double"));
}

template<typename T>
bool TNumeric<T>::isZero() {
	return this->getValue() == 0 || this->getValue() == 0.0;
}

template<typename T>
void TNumeric<T>::dump() {
	std::cout << "Numeric: " << value << " ";
	dumpAttrLn();
}

//impl spec short---
template<>
Object_* TNumeric<short>::add(Object_* right) {
	return this_cast(right, [&](Numeric* n, PShort* self) {
		if (n == nullptr) {
			String* retS = toString(right);
			return static_cast<Object_*>(retS);
		}
		return n->addShort(self);
	});
}

template<>
Object_* TNumeric<short>::sub(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) { return n->subShort(self); });
}

template<>
Object_* TNumeric<short>::mul(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) { return n->mulShort(self); });
}

template<>
Object_* TNumeric<short>::div(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) { return n->divShort(self); });
}

template<>
Object_* TNumeric<short>::mod(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) { return n->modShort(self); });
}

template<>
Object_* TNumeric<short>::equals(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) {
		if (n == nullptr) {
			return (Object_*)Boolean::getFalse();
		}
		return n->equalsShort(self);
	});
}

template<>
Object_* TNumeric<short>::biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) {
		return n->smallestShort(self);
	});
}

template<>
Object_* TNumeric<short>::e_biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) {
		return n->e_smallestShort(self);
	});
}

template<>
Object_* TNumeric<short>::smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) {
		return n->biggestShort(self);
	});
}

template<>
Object_* TNumeric<short>::e_smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PShort* self) {
		return n->e_biggestShort(self);
	});
}
//---impl spec short

//impl spec int---
template<>
Object_* TNumeric<int>::add(Object_* right) {
	return this_cast(right, [&](Numeric* n, PInteger* self) {
		if (n == nullptr) {
			String* retS = toString(right);
			return static_cast<Object_*>(retS);
		}
		return n->addInt(self); 
	});
}

template<>
Object_* TNumeric<int>::sub(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) { return n->subInt(self); });
}

template<>
Object_* TNumeric<int>::mul(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) { return n->mulInt(self); });
}

template<>
Object_* TNumeric<int>::div(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) { return n->divInt(self); });
}

template<>
Object_* TNumeric<int>::mod(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) { return n->modInt(self); });
}

template<>
Object_* TNumeric<int>::equals(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) { 
		if (n == nullptr) {
			return (Object_*)Boolean::getFalse();
		}
		return n->equalsInt(self); 
	});
}

template<>
Object_* TNumeric<int>::biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) {
		return n->smallestInt(self);
	});
}

template<>
Object_* TNumeric<int>::e_biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) {
		return n->e_smallestInt(self);
	});
}

template<>
Object_* TNumeric<int>::smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) {
		return n->biggestInt(self);
	});
}

template<>
Object_* TNumeric<int>::e_smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PInteger* self) {
		return n->e_biggestInt(self);
	});
}
//---impl spec int

//impl spec long---
template<>
Object_* TNumeric<long>::add(Object_* right) {
	return this_cast(right, [&](Numeric* n, PLong* self) {
		if (n == nullptr) {
			String* retS = toString(right);
			return static_cast<Object_*>(retS);
		}
		return n->addLong(self);
	});
}

template<>
Object_* TNumeric<long>::sub(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) { return n->subLong(self); });
}

template<>
Object_* TNumeric<long>::mul(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) { return n->mulLong(self); });
}

template<>
Object_* TNumeric<long>::div(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) { return n->divLong(self); });
}

template<>
Object_* TNumeric<long>::mod(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) { return n->modLong(self); });
}

template<>
Object_* TNumeric<long>::equals(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) {
		if (n == nullptr) {
			return (Object_*)Boolean::getFalse();
		}
		return n->equalsLong(self);
	});
}

template<>
Object_* TNumeric<long>::biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) {
		return n->smallestLong(self);
	});
}

template<>
Object_* TNumeric<long>::e_biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) {
		return n->e_smallestLong(self);
	});
}

template<>
Object_* TNumeric<long>::smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) {
		return n->biggestLong(self);
	});
}

template<>
Object_* TNumeric<long>::e_smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PLong* self) {
		return n->e_biggestLong(self);
	});
}
//---impl spec long

//impl spec float---
template<>
Object_* TNumeric<float>::add(Object_* right) {
	return this_cast(right, [&](Numeric* n, PFloat* self) { 
		if (n == nullptr) {
			return static_cast<Object_*>(toString(right));
		}
		return n->addFloat(self); 
	});
}

template<>
Object_* TNumeric<float>::sub(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) { return n->subFloat(self); });
}

template<>
Object_* TNumeric<float>::mul(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) { return n->mulFloat(self); });
}

template<>
Object_* TNumeric<float>::div(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) { return n->divFloat(self); });
}

template<>
Object_* TNumeric<float>::mod(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) { return n->modFloat(self); });
}

template<>
Object_* TNumeric<float>::equals(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) { return n->equalsFloat(self); });
}

template<>
Object_* TNumeric<float>::biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) {
		return n->smallestFloat(self);
	});
}

template<>
Object_* TNumeric<float>::e_biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) {
		return n->e_smallestFloat(self);
	});
}

template<>
Object_* TNumeric<float>::smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) {
		return n->biggestFloat(self);
	});
}

template<>
Object_* TNumeric<float>::e_smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PFloat* self) {
		return n->e_biggestFloat(self);
	});
}
//---impl spec float

//impl spec double---
template<>
Object_* TNumeric<double>::add(Object_* right) {
	return this_cast(right, [&](Numeric* n, PDouble* self) {
		if (n == nullptr) {
			String* retS = toString(right);
			return static_cast<Object_*>(retS);
		}
		return n->addDouble(self);
	});
}

template<>
Object_* TNumeric<double>::sub(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) { return n->subDouble(self); });
}

template<>
Object_* TNumeric<double>::mul(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) { return n->mulDouble(self); });
}

template<>
Object_* TNumeric<double>::div(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) { return n->divDouble(self); });
}

template<>
Object_* TNumeric<double>::mod(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) { return n->modDouble(self); });
}

template<>
Object_* TNumeric<double>::equals(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) {
		if (n == nullptr) {
			return (Object_*)Boolean::getFalse();
		}
		return n->equalsDouble(self);
	});
}

template<>
Object_* TNumeric<double>::biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) {
		return n->smallestDouble(self);
	});
}

template<>
Object_* TNumeric<double>::e_biggest(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) {
		return n->e_smallestDouble(self);
	});
}

template<>
Object_* TNumeric<double>::smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) {
		return n->biggestDouble(self);
	});
}

template<>
Object_* TNumeric<double>::e_smallest(Object_* right) {
	return this_cast(right, [](Numeric* n, PDouble* self) {
		return n->e_biggestDouble(self);
	});
}
//---impl spec double
#endif // !BEAN_ENV_TNUMERICIMPL_H
