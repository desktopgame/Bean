#include "SetMethod.h"
#include "Class.h"
#include "Field.h"
#include "Null.h"
#include "Object_.h"
#include "Parameter.h"

//public method---
SetMethod::SetMethod(ClassSPtr classz, const std::string& propertyName, const std::string& methodName)
 : Method(classz, Modifier(Modifier::PUBLIC), methodName) {
	this->propertyName = propertyName;
	this->methodName = methodName;
	addParameter(new Parameter("arg"));
}

SetMethod::~SetMethod() {
}

Object_ * const SetMethod::execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) {
	ClassWPtr cls = getClass();
	ClassSPtr clsSptr = cls.lock();
	Field* fld = clsSptr->findField(propertyName);
	fld->setValue(invoker, args.at(0));
	return Null::getInstance();
}
//---public method
