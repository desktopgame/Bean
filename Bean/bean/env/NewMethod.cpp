#include "NewMethod.h"
#include "Class.h"
#include "ClassLoader.h"
#include "Constructor_.h"
#include "Parameter.h"
#include "gc/Block.h"
#include "gc/GCLock.h"

//public method---
NewMethod::NewMethod(Constructor_* cons) 
 : Method(
	cons->getClass().lock(), 
	Modifier(cons->getModifier(), Modifier::STATIC),
	"new"
	) {
	for (int i = 0; i < cons->getParameterCount(); i++) {
		Parameter* param = cons->getParameterAt(i);
		addParameter(param->clone());
	}
	this->cons = cons;
}

NewMethod::~NewMethod() {
}

Object_ * const NewMethod::execute(Object_ * invoker, std::vector<Object_*> args, bool currentClassLoader) {
	auto gcLock = GCLock();
	int dep = Block::getInstance()->getDepth();
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	ClassWPtr cls = getClass();
	ClassSPtr clsSptr = cls.lock();
	ClassLoader::pushCurrentClassLoader(clsSptr->getClassLoader().lock());
	//Constructor_* cons = cl->findConstructor(cll, getArgumentCount());
	Object_* retVal = cons->execute(nullptr, args, true);
	ClassLoader::popCurrentClassLoader();
	return retVal;
}
//---public method
