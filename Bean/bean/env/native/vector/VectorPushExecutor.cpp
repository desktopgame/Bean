#include "VectorPushExecutor.h"
#include "../../user/UserVector.h"

VectorPushExecutor::VectorPushExecutor() {
}

VectorPushExecutor::~VectorPushExecutor() {
}

Object_ * const VectorPushExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	Object_* elem = args.at(0);
	uv->push(elem);
	return getNull();
}
