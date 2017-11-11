#include "DelegateMethod.h"
#include "Class.h"
#include "Delegate.h"
#include "Parameter.h"
#include "user/UserDelegate.h"
//public method---
DelegateMethod::DelegateMethod(Object_* inv, const std::string& name, UserDelegate* ud)
 : Method(inv->getClass(), Modifier(Modifier::PUBLIC), name) {
	this->ud = ud;
	for (int i = 0; i < ud->getDelegate()->requestArgumentCount(); i++) {
		addParameter(new Parameter("arg" + std::to_string(i)));
	}
}

DelegateMethod::~DelegateMethod() {
}

Object_ * const DelegateMethod::execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) {
	ClassLoaderSPtr cll = getClass().lock()->getClassLoader().lock();
	ClassLoader::pushCurrentClassLoader(cll);
	auto ret = ud->call(args);
	ClassLoader::popCurrentClassLoader();
	return ret;
}
//---public method
