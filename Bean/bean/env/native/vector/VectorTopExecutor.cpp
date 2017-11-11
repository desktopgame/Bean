#include "VectorTopExecutor.h"
#include "../../user/UserVector.h"

VectorTopExecutor::VectorTopExecutor() {
}

VectorTopExecutor::~VectorTopExecutor() {
}

Object_ * const VectorTopExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	if (uv->size() == 0) {
		return getNull();
	}
	return uv->top();
}
