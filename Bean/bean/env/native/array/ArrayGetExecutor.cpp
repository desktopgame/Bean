#include "ArrayGetExecutor.h"
#include <sstream>
#include "../../Numeric.h"
#include "../../user/UserArray.h"

//public method---
ArrayGetExecutor::ArrayGetExecutor() {
}

ArrayGetExecutor::~ArrayGetExecutor() {
}

Object_ * const ArrayGetExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserArray* arr = invoker->asUserArray();
	Numeric* index = arg_cast(Numeric, 0, "Integer");
	if (Exception::checkIndexRange(index, 0, arr->getLength() - 1)) {
		return getNull();
	}
	return arr->get(index->getCInt());
}
//---public method
