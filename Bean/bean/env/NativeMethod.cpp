#include "NativeMethod.h"
#include "Class.h"
#include "ClassLoader.h"
#include "Exception.h"
#include "Null.h"
#include "native/NativeMethodExecutor.h"
#include "native/NativeMethodRegistry.h"
#include "../threads/Thread.h"

//public method---
NativeMethod::NativeMethod(ClassSPtr classz, Modifier modifier, std::string name, std::string package)
	: Method(classz, modifier, name) {
	this->package = package;
	this->delgate = nullptr;
}

NativeMethod::~NativeMethod() {
	if (isSingular) {
		delete delgate;
	}
}

NativeMethod * NativeMethod::singular(NativeMethodExecutor * executor) {
	this->delgate = executor;
	this->isSingular = true;
	return this;
}

Object_ * const NativeMethod::execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) {
	ClassWPtr cls = getClass();
	ClassSPtr clsSptr = cls.lock();
	getDelegate();
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	if (delgate == nullptr) {
		std::string clsName = clsSptr->getName();
		std::string mthName = getName();
		int n = getParameterCount();
		std::string prmStr = std::to_string(n);
		Exception::throw_e_simple("api.exc.NoNativeMethodError", (clsName + "#" + mthName + "(" + prmStr +  ")") + " ‚Ì C++ŽÀ‘•‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñB");
		return Null::getInstance();
	}
	Object_* ret = delgate->execute(this, invoker, args);
	return ret;
}

Object_ * NativeMethod::newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) {
	return getDelegate()->newObject(classz, cons, args);
}

NativeMethodExecutor * NativeMethod::getDelegate() {
	ClassWPtr cls = getClass();
	ClassSPtr clsSptr = cls.lock();
	if (this->delgate == nullptr) {
		this->delgate = NativeMethodRegistry::getInstance()->get(
			package + "." +
			clsSptr->getName() + "#" +
			getName() + "(" +
			std::to_string(getParameterCount()) + ")"
			);
	}
	return delgate;
}
//---public method
