#include "ASTNullFactor.h"
#include "../env/Null.h"
#include "../env/Object_.h"

//public method---
ASTNullFactor::ASTNullFactor() {
}

ASTNullFactor::~ASTNullFactor() {
}

Object_ * ASTNullFactor::eval() {
	return Null::getInstance();
}

std::string ASTNullFactor::format() const {
	return "null";
}
IMPL_MAKE_SHARED_0_CPP(ASTNullFactor)
//---public method
