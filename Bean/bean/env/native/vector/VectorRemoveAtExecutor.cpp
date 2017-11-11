#include "VectorRemoveAtExecutor.h"
#include "../../Numeric.h"
#include "../../user/UserVector.h"

VectorRemoveAtExecutor::VectorRemoveAtExecutor() {
}

VectorRemoveAtExecutor::~VectorRemoveAtExecutor() {
}

Object_ * const VectorRemoveAtExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserVector* uv = dynamic_cast<UserVector*>(invoker);
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	if (Exception::checkIndexRange(index, 0, uv->size() - 1)) {
		return getNull();
	}
	uv->removeAt(index->getCInt());
	return getNull();
}
