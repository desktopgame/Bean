#include "ASTDivOperator.h"

//public method---
ASTDivOperator::ASTDivOperator() {
}

ASTDivOperator::~ASTDivOperator() {
}

Object_ * ASTDivOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->div(getRight());
	buffer_end();
	return retVal;
}

std::string ASTDivOperator::format() const {
	return "/";
}
IMPL_MAKE_SHARED_0_CPP(ASTDivOperator)
//---public method
