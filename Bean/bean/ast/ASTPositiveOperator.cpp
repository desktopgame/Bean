#include "ASTPositiveOperator.h"

//public method---
ASTPositiveOperator::ASTPositiveOperator() {
}

ASTPositiveOperator::~ASTPositiveOperator() {
}

Object_ * ASTPositiveOperator::eval() {
	return getCondition()->eval();
}

std::string ASTPositiveOperator::format() const {
	return "positive";
}
IMPL_MAKE_SHARED_0_CPP(ASTPositiveOperator)
//---public method