#include "ASTBiggestOperator.h"

//public method---
ASTBiggestOperator::ASTBiggestOperator() {
}

ASTBiggestOperator::~ASTBiggestOperator() {
}

Object_ * ASTBiggestOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->biggest(getRight());
	buffer_end();
	return retVal;
}

std::string ASTBiggestOperator::format() const {
	return ">";
}
IMPL_MAKE_SHARED_0_CPP(ASTBiggestOperator)
//---public method
