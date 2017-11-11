#include "UserPattern.h"
#include "../Package.h"
//public method---
UserPattern::UserPattern() 
 : Object_(nullptr) {
}

UserPattern::~UserPattern() {
}

Object_ * UserPattern::clone() {
	return nullptr;
}

void UserPattern::compile(const std::string & patternText) {
	this->patternText = patternText;
	this->regex = std::regex(patternText);
}

std::regex * UserPattern::getRegex() {
	return &regex;
}

void UserPattern::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Pattern"));
}
//---public method