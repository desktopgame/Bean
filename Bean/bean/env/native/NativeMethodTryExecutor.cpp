#include "NativeMethodTryExecutor.h"
#include <stdexcept>
#include "../Exception.h"
//public method---
NativeMethodTryExecutor::NativeMethodTryExecutor(NativeMethodExecutor* nmproxy) {
	this->nmproxy = nmproxy;
}

NativeMethodTryExecutor::~NativeMethodTryExecutor() {
	delete nmproxy;
}

Object_ * const NativeMethodTryExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	try {
		Object_* ret = nmproxy->execute(proxy, invoker, args);
		return ret;
	} catch (std::exception e) {
		Exception::throw_e_simple("api.exc.RuntimeException", e.what());
		return getNull();
	}
}

Object_ * NativeMethodTryExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	try {
		Object_* ret = nmproxy->newObject(classz, cons, args);
		return ret;
	} catch (std::exception e) {
		Exception::throw_e_simple("api.exc.RuntimeException", e.what());
		return getNull();
	}
}
//---public method
