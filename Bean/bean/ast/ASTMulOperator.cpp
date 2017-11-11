#include "ASTMulOperator.h"

//public method---
ASTMulOperator::ASTMulOperator() {
}

ASTMulOperator::~ASTMulOperator() {
}

Object_ * ASTMulOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->mul(getRight());
	buffer_end();
	return retVal;
}

std::string ASTMulOperator::format() const {
	return "*";
}
IMPL_MAKE_SHARED_0_CPP(ASTMulOperator)
//---public method
