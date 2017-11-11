#include "DelegateNewInstanceExecutor.h"
#include "../../../env/Class.h"
#include "../../../env/MethodDelegate.h"
#include "../../../env/Numeric.h"
#include "../../../env/Package.h"
#include "../../../env/String.h"
#include "../../../env/user/UserDelegate.h"

//public method---
DelegateNewInstanceExecutor::DelegateNewInstanceExecutor() {
}

DelegateNewInstanceExecutor::~DelegateNewInstanceExecutor() {
}

Object_ * const DelegateNewInstanceExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* className = arg_cast(String, 0, "String");
	String* methodName = arg_cast(String, 1, "String");
	Numeric* argCount = arg_cast(Numeric, 2, "Integer");
	Object_* arg4 = args.at(3);
	ClassSPtr classz = Package::getClass(*className->getCString());
	if (classz == NULL) {
		return getNull();
	}
	Method* method = classz->findMethod(*methodName->getCString(), argCount->getCInt(), false);
	if (method == nullptr) {
		return getNull();
	}
	return
		//メソッド参照ではクロージャを使用しない
		new UserDelegate(
			classz->getClassLoader().lock(),
			new MethodDelegate(
			//					new Reference(arg4->getValue()),
			method->getModifier().isStatic() ? nullptr : arg4,
			method
			)
		);
}
//---public method
