#include "VectorInsertExecutor.h"
#include "../../Numeric.h"
#include "../../user/UserVector.h"
//public method---
VectorInsertExecutor::VectorInsertExecutor() {
}

VectorInsertExecutor::~VectorInsertExecutor() {
}

Object_ * const VectorInsertExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = static_cast<UserVector*>(invoker);
	Numeric* offs = arg_cast(Numeric, 0, "Numeric");
	Object_* elem = args.at(1);
	uv->insert(offs->getCInt(), elem);
	return getNull();
}
//---public method
