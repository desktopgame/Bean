#include "ASTAddOperator.h"
#include "../env/Object_.h"

//public method---
ASTAddOperator::ASTAddOperator() {
}

ASTAddOperator::~ASTAddOperator() {
}

Object_ * ASTAddOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->add(getRight());
	buffer_end();
	return retVal;
}

std::string ASTAddOperator::format() const {
	return "+";
}
IMPL_MAKE_SHARED_0_CPP(ASTAddOperator);
//---public method
