#include "UserObject.h"
#include "../Class.h"
#include "../ClassLoader.h"
#include "../Field.h"
#include "../Null.h"
#include "../gc/Heap.h"

//public method---
UserObject::UserObject(ClassSPtr classz)
	: Object_(classz) {
	classz->allocateField(this);
}

UserObject::~UserObject() {
	//getClass()->freeField(this);
	if (getClass()->isSingular()) {
		//getClass()->deleteInstance();
	}
}

Object_ * UserObject::clone() {
	return nullptr;
}

Object_ * UserObject::add(Object_ * right) {
	return evalImpl(right, "op_add");
}

Object_ * UserObject::sub(Object_ * right) {
	return evalImpl(right, "op_sub");
}

Object_ * UserObject::mul(Object_ * right) {
	return evalImpl(right, "op_mul");
}

Object_ * UserObject::div(Object_ * right) {
	return evalImpl(right, "op_div");
}

Object_ * UserObject::mod(Object_ * right) {
	return evalImpl(right, "op_mod");
}

Object_ * UserObject::equals(Object_ * right) {
	return evalImpl(right, "op_equals");
}

Object_ * UserObject::biggest(Object_ * right) {
	return Null::getInstance();
}

Object_ * UserObject::e_biggest(Object_ * right) {
	return Null::getInstance();
}

Object_ * UserObject::smallest(Object_ * right) {
	return Null::getInstance();
}

Object_ * UserObject::e_smallest(Object_ * right) {
	return Null::getInstance();
}

void UserObject::dump() {
	std::cout << "UserObject: " << getClass()->getName() << std::endl;
}

UserObject * UserObject::asUserObject() {
	return this;
}

Object_ * UserObject::evalImpl(Object_ * right, std::string name) {
	Object_* arg = right;
	Object_* ret = execute(name, arg);
	Object_* retVal = ret;
//	arg->keep();
//	arg->deleteOnlyRef();
//	ret->keep();
//	ret->deleteOnlyRef();
	return retVal;
}
//---public method
