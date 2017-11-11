#include "VectorBackExecutor.h"
#include "../../user/UserVector.h"

VectorBackExecutor::VectorBackExecutor() {
}

VectorBackExecutor::~VectorBackExecutor() {
}

Object_ * const VectorBackExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	return uv->back();
}
