#include "VectorSetExecutor.h"
#include "../../Numeric.h"
#include "../../user/UserVector.h"

VectorSetExecutor::VectorSetExecutor() {
}

VectorSetExecutor::~VectorSetExecutor() {
}

Object_ * const VectorSetExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	Object_* elem = args.at(1);
	if (Exception::checkIndexRange(index, 0, uv->size() - 1)) {
		return getNull();
	}
	uv->set(index->getCInt(), elem);
	return getNull();
}
