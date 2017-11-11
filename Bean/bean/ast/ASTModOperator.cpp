#include "ASTModOperator.h"

//public method---
ASTModOperator::ASTModOperator() {
}

ASTModOperator::~ASTModOperator() {
}

Object_ * ASTModOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->mod(getRight());
	buffer_end();
	return retVal;
}

std::string ASTModOperator::format() const {
	return "%";
}
IMPL_MAKE_SHARED_0_CPP(ASTModOperator)
//---public method
