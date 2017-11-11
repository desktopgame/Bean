#include "ASTEqualOperator.h"

//public method---
ASTEqualOperator::ASTEqualOperator() {
}

ASTEqualOperator::~ASTEqualOperator() {
}

Object_ * ASTEqualOperator::eval() {
	buffer_begin();
	auto left = getLeft();
	auto right = getRight();
	Object_* retVal = left->equals(right);
	buffer_end();
	return retVal;
}

std::string ASTEqualOperator::format() const {
	return "==";
}
IMPL_MAKE_SHARED_0_CPP(ASTEqualOperator)
//---public method
