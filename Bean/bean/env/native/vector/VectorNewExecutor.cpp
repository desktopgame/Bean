#include "VectorNewExecutor.h"
#include "../../user/UserVector.h"

VectorNewExecutor::VectorNewExecutor() {
}

VectorNewExecutor::~VectorNewExecutor() {
}

Object_ * const VectorNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * VectorNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	return new UserVector();
}
