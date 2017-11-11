#include "NativeMethodExecutor.h"
#include <sstream>
#include "../../env/Boolean.h"
#include "../../env/Character.h"
#include "../../env/Class.h"
#include "../../env/ClassLoader.h"
#include "../../env/Exception.h"
#include "../../env/Method.h"
#include "../../env/Null.h"
#include "../../env/Numeric.h"
#include "../../env/String.h"
#include "../../threads/Thread.h"
#include "../../env/gc/Block.h"
#include "../../env/gc/GCLock.h"
#include "../../env/user/UserObject.h"
//pubic method---
NativeMethodExecutor::NativeMethodExecutor() {
}

NativeMethodExecutor::~NativeMethodExecutor() {
}

Object_ * NativeMethodExecutor::newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) {
	return new UserObject(classz);
}
//---public method

//protected method---
void NativeMethodExecutor::throw_(const std::string& className, std::vector<Object_*> args) {
	Thread::getCurrent()->setException(Class::dynamicNewInstance(className, args));
}

void NativeMethodExecutor::throw_simple(const std::string& className, std::string msg) {
	std::vector<Object_*> args =  std::vector<Object_*>();
	args.push_back(Null::getInstance());
	args.push_back(String::allocString(msg));

	throw_(className, args);
}

Object_ * NativeMethodExecutor::getNull() {
	return Null::getInstance();
}

Object_ * NativeMethodExecutor::getBoolean(bool b) {
	return Boolean::get(b);
}

Object_ * NativeMethodExecutor::getInteger(int i) {
	return Numeric::newInteger(i);
}

Object_ * NativeMethodExecutor::getCharacter(BChar bc) {
	return new Character(bc);
}
//---protected method
