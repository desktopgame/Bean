#include "ASTNotEqualsOperator.h"
#include "../env/Boolean.h"
#include "../env/Object_.h"

//public method---
ASTNotEqualsOperator::ASTNotEqualsOperator() {
}

ASTNotEqualsOperator::~ASTNotEqualsOperator() {
}

Object_ * ASTNotEqualsOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->equals(getRight());
	Object_* obj = retVal;
	Boolean* b = obj->asBoolean();
	Object_* retVal2 = Boolean::get(!b->of());
	buffer_end();
	return retVal2;
}

std::string ASTNotEqualsOperator::format() const {
	return "!=";
}
IMPL_MAKE_SHARED_0_CPP(ASTNotEqualsOperator)
//---public method
