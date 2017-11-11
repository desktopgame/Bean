#include "VectorRemoveExecutor.h"
#include "../../user/UserVector.h"

VectorRemoveExecutor::VectorRemoveExecutor() {
}

VectorRemoveExecutor::~VectorRemoveExecutor() {
}

Object_ * const VectorRemoveExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	Object_* o = args.at(1);
	uv->remove(o);
	return getNull();
}
