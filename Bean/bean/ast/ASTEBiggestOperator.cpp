#include "ASTEBiggestOperator.h"

//public method---
ASTEBiggestOperator::ASTEBiggestOperator() {
}

ASTEBiggestOperator::~ASTEBiggestOperator() {
}

Object_ * ASTEBiggestOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->e_biggest(getRight());
	buffer_end();
	return retVal;
}

std::string ASTEBiggestOperator::format() const {
	return ">=";
}
IMPL_MAKE_SHARED_0_CPP(ASTEBiggestOperator)
//---public method
