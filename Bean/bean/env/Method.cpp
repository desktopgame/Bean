#include "Method.h"
#include "Class.h"
#include "Object_.h"
#include "Parameter.h"
#include "gc/Block.h"
#include "user/UserObject.h"

//public method---
Method::Method(ClassSPtr classz, Modifier modifier, std::string name)
	: Member(classz, modifier, name) {
	this->parameters = std::vector<Parameter*>();
}

Method::~Method() {
	for (int i = parameters.size() - 1; i >= 0; i--) {
		Parameter* param = parameters.at(i);
		parameters.erase(parameters.begin() + i);
		delete param;
	}
	parameters.clear();
}

void Method::addParameter(Parameter * param) {
	this->parameters.push_back(param);
}

Parameter * const Method::getParameterAt(int index) const {
	return parameters.at(index);
}

void Method::removeParameterAt(int index) {
	Parameter* param = parameters.at(index);
	parameters.erase(parameters.begin() + index);
	delete param;
}

int Method::getParameterCount() const {
	return parameters.size();
}

Object_ * const Method::execute(Object_ * const invoker, std::vector<Object_*> args) {
	return execute(invoker, args, true);
}

Object_ * Method::newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) {
	int dep = Block::getInstance()->getDepth();
	return new UserObject(classz);
}

std::string Method::toUID() {
	return getLocation();
}

std::string Method::getLocation() {
	ClassWPtr cls = getClass();
	ClassSPtr clsSPtr = cls.lock();
	if (clsSPtr) {
		return clsSPtr->getName() + "#" + getName() + "(" + std::to_string(getParameterCount()) + ")";
	}
	return "#" + getName() + "(" + std::to_string(getParameterCount()) + ")";
}
//---public method
