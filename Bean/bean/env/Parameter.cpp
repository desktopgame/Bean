#include "Parameter.h"

//public method---
Parameter::Parameter(const std::string& name) {
	this->name = name;
}

Parameter::~Parameter() {
}

std::string Parameter::getName() {
	return this->name;
}

Parameter * Parameter::clone() {
	return new Parameter(name);
}
//---public method