#include "MessageInfo.h"
#include "Class.h"
#include "Function.h"
#include "Method.h"

//public method---
MessageInfo::MessageInfo(ClassLoaderSPtr classLoader, ClassSPtr classz, Method* method) {
	this->classLoader = std::weak_ptr<ClassLoader>(classLoader);
	this->classz = std::weak_ptr<Class>(classz);
	this->method = method;
}

MessageInfo::MessageInfo(ClassLoaderSPtr classLoader, ClassSPtr classz, Function * func) {
	this->classLoader = std::weak_ptr<ClassLoader>(classLoader);
	this->classz = std::weak_ptr<Class>(classz);
	this->func = func;
}

MessageInfo* MessageInfo::createTop() {
	return new MessageInfo(true);
}

MessageInfo::~MessageInfo() {
}

ClassLoaderWPtr MessageInfo::getClassLoader() const {
	return this->classLoader;
}

ClassSPtr MessageInfo::getClass() const {
	return this->classz.lock();
}

Method * const MessageInfo::getMethod() const {
	return this->method;
}

Function * const MessageInfo::getFunction() const {
	return func;
}

std::string MessageInfo::getLocation() {
	if (top) {
		return "root";
	}
	std::string clsName = classz.lock() == nullptr ? "root" : getClass()->getName();
	std::string callName = func == nullptr ? getMethod()->getName() : getFunction()->getName();
	return clsName + "#" + callName;
}
//---public method

//private method---
MessageInfo::MessageInfo(bool top) {
	this->top = top;
}
//---private method
