#include "Numeric.h"
#include "TNumeric.h"
#include "../launch/Bean.h"
//#include <boost/signals2.hpp>

//public method---
Numeric::Numeric(ClassSPtr classz) : Object_(classz) {

}

Numeric::~Numeric() {
}

Numeric * Numeric::newShort(short val) {
	return new PShort(val);
}

Numeric * Numeric::newInteger(int val) {
	return new PInteger(val);
}

Numeric * Numeric::newLong(long val) {
	return new PLong(val);
}

Numeric * Numeric::newFloat(float val) {
	return new PFloat(val);
}

Numeric * Numeric::newDouble(double val) {
	return new PDouble(val);
}

bool Numeric::isPrimitive() {
	return true;
}

Numeric * Numeric::asNumeric() {
	return this;
}
//---public method
