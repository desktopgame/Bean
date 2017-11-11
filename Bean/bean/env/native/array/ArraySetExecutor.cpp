#include "ArraySetExecutor.h"
#include <sstream>
#include "../../Numeric.h"
#include "../../gc/Heap.h"
#include "../../user/UserArray.h"

//public method---
ArraySetExecutor::ArraySetExecutor() {
}

ArraySetExecutor::~ArraySetExecutor() {
}

Object_ * const ArraySetExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserArray* arr = invoker->asUserArray();
	Numeric* index = arg_cast(Numeric, 0, "Integer");
	if (Exception::checkIndexRange(index, 0, arr->getLength() - 1)) {
		return getNull();
	}
	Object_* ref = args.at(1);
	arr->set(index->getCInt(), ref);
	return getNull();
}
//---public method
