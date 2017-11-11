#include "VectorAddExecutor.h"
#include "../../user/UserVector.h"

VectorAddExecutor::VectorAddExecutor() {
}

VectorAddExecutor::~VectorAddExecutor() {
}

Object_ * const VectorAddExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	uv->vadd(args.at(0));
	return getNull();
}
