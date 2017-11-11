#include "VectorSizeExecutor.h"
#include "../../user/UserVector.h"

VectorSizeExecutor::VectorSizeExecutor() {
}

VectorSizeExecutor::~VectorSizeExecutor() {
}

Object_ * const VectorSizeExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	return getInteger(uv->size());
}
