#include "DelegateConstructor.h"
#include "Object_.h"
#include "../util/NotImplException.h"
//public method---
DelegateConstructor::DelegateConstructor(ClassSPtr cls, Constructor_* cons)
 : Constructor_(cls, cons->getModifier(), cons->getName(), cons->getProxy()) {
	this->cons = cons;
	this->cls = std::weak_ptr<Class>(cls);
	this->deleteProxy = false;
}

DelegateConstructor::~DelegateConstructor() {
}

void DelegateConstructor::setChain(std::shared_ptr<ASTConstructorChain> chain) {
	this->chain = chain;
}

std::shared_ptr<ASTConstructorChain> DelegateConstructor::getChain() const {
	return chain;
}

void DelegateConstructor::addParameter(Parameter * param) {
	throw NotImplException();
}

void DelegateConstructor::removeParameterAt(int index) {
	throw NotImplException();
}

Object_ * const DelegateConstructor::execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) {
	Object_* obj = cons->execute(invoker, args, currentClassLoader);
	obj->chainConstruct(this->cls.lock());
	return obj;
}

Method * const DelegateConstructor::getProxy() const {
	return cons->getProxy();
}
//---public method