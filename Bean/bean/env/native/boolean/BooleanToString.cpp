#include "BooleanToString.h"
#include "../../Boolean.h"
#include "../../String.h"

//public method---
BooleanToString::BooleanToString() {
}

BooleanToString::~BooleanToString() {
}

Object_ * const BooleanToString::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* obj = invoker;
	Boolean* b = obj->asBoolean();
	return String::allocString(b->of() ? "true" : "false");
}
//---public method