#include "VectorPopExecutor.h"
#include "../../user/UserVector.h"

VectorPopExecutor::VectorPopExecutor() {
}

VectorPopExecutor::~VectorPopExecutor() {
}

Object_ * const VectorPopExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	if (uv->size() == 0) {
		return getNull();
	}
	uv->pop();
	return getNull();
}
