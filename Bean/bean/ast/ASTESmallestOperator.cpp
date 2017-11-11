#include "ASTESmallestOperator.h"
//public method---
ASTESmallestOperator::ASTESmallestOperator() {
}

ASTESmallestOperator::~ASTESmallestOperator() {
}

Object_ * ASTESmallestOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->e_smallest(getRight());
	buffer_end();
	return retVal;
}

std::string ASTESmallestOperator::format() const {
	return "<=";
}
IMPL_MAKE_SHARED_0_CPP(ASTESmallestOperator)
//---public method
