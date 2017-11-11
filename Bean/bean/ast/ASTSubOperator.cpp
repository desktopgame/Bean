#include "ASTSubOperator.h"

//public method---
ASTSubOperator::ASTSubOperator() {
}

ASTSubOperator::~ASTSubOperator() {
}

Object_ * ASTSubOperator::eval() {
	buffer_begin();
	Object_* retVal = getLeft()->sub(getRight());
	buffer_end();
	return retVal;
}

std::string ASTSubOperator::format() const {
	return "-";
}
IMPL_MAKE_SHARED_0_CPP(ASTSubOperator)
//---public method
