#include "ArrayNewExecutor.h"
#include "../../Class.h"
#include "../../ClassLoader.h"
#include "../../Constructor_.h"
#include "../../Exception.h"
#include "../../Numeric.h"
#include "../../Object_.h"
#include "../../String.h"
#include "../../user/UserArray.h"
#include "../../../threads/Thread.h"

//public method---
ArrayNewExecutor::ArrayNewExecutor() {
}

ArrayNewExecutor::~ArrayNewExecutor() {
}

Object_ * const ArrayNewExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * ArrayNewExecutor::newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) {
	Numeric* index = args.at(0)->asNumeric();
	int cIndex = index->getCInt();
	//Numericå^Ç≈Ç»Ç©Ç¡ÇΩ
	if (index == nullptr) {
		Exception::throw_e(
			Class::dynamicStaticCall("api.exc.TypeCastError", "newInstance", std::vector<Object_*> {
				getNull(),
				String::allocString("Numeric"),
				String::allocString(args.at(0)->getClass()->getName())
			})
		);
		return getNull();
	}
	if (Exception::checkIndexNegative(index)) {
		return getNull();
	}
	UserArray* ret = new UserArray();
	ret->alloc(index->getCInt());
	return ret;
}
//---public method
