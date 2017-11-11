#include "MethodDelegate.h"
#include "Method.h"
#include "../threads/Thread.h"

//public method---
MethodDelegate::MethodDelegate(Object_* invoker, Method* method) {
	this->invoker = invoker;
	this->method = method;
}

MethodDelegate::~MethodDelegate() {
}

Object_ * MethodDelegate::call(ThreadSPtr t, ClassLoaderSPtr cll, std::vector<Object_*> args) {
	return call(cll, args);
}

Object_ * MethodDelegate::call(ClassLoaderSPtr cll, std::vector<Object_*> args) {
	Object_* retVal = method->execute(invoker, args);
	return retVal;
}

int MethodDelegate::requestArgumentCount() {
	return method->getParameterCount();
}
//---public method