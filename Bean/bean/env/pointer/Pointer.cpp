#include "Pointer.h"

Pointer::Pointer() {
}

Pointer::~Pointer() {
}

Object_ * Pointer::operator->() {
	return getValue();
}
