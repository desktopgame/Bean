#include "ASTSmallestOperator.h"
#include "../env/Object_.h"
//public method---
ASTSmallestOperator::ASTSmallestOperator() {
}

ASTSmallestOperator::~ASTSmallestOperator() {
}

Object_ * ASTSmallestOperator::eval() {
	buffer_begin();
	auto left = getLeft()->eval();
	auto right = getRight()->eval();
	Object_* retVal = getLeft()->smallest(getRight());
	buffer_end();
	return retVal;
}

std::string ASTSmallestOperator::format() const {
	return "<";
}
IMPL_MAKE_SHARED_0_CPP(ASTSmallestOperator)
//---public method
