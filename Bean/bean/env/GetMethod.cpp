#include "GetMethod.h"
#include "Class.h"
#include "Field.h"
#include "Object_.h"
#include "Parameter.h"

//public method---
GetMethod::GetMethod(ClassSPtr classz, const std::string& propertyName, const std::string& methodName)
 : Method(classz, Modifier(Modifier::PUBLIC), methodName) {
	this->propertyName = propertyName;
	this->methodName = methodName;
}

GetMethod::~GetMethod() {
}

Object_ * const GetMethod::execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) {
	ClassWPtr cls = getClass();
	ClassSPtr clsSptr = cls.lock();
	Field* fld = clsSptr->findField(propertyName);
	Object_* ret = fld->getValue(invoker);
	return ret;
}
//---public method
