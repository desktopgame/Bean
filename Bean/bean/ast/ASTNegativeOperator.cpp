#include "ASTNegativeOperator.h"
#include "../env/Numeric.h"
#include "../env/Object_.h"

//public method---
ASTNegativeOperator::ASTNegativeOperator() {
}

ASTNegativeOperator::~ASTNegativeOperator() {
}

Object_ * ASTNegativeOperator::eval() {
	buffer_begin();
	Object_* obj = getCondition()->eval();
	Object_* newObj = obj->mul(Numeric::newInteger(-1));
	buffer_end();
	return newObj;
}

std::string ASTNegativeOperator::format() const {
	return "negative";
}
IMPL_MAKE_SHARED_0_CPP(ASTNegativeOperator)
//---public method
