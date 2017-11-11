#include "ASTNotOperator.h"
#include "../env/Boolean.h"
#include "../env/Object_.h"

//public method---
ASTNotOperator::ASTNotOperator() {
}

ASTNotOperator::~ASTNotOperator() {
}

Object_ * ASTNotOperator::eval() {
	buffer_begin();
	Object_* retVal = getCondition()->eval();
	Object_* obj = retVal;
	Boolean* b = obj->asBoolean();
	Object_* reversed = Boolean::get(!b->of());
	buffer_end();
	return reversed;
}

std::string ASTNotOperator::format() const {
	return "!";
}
IMPL_MAKE_SHARED_0_CPP(ASTNotOperator)
//---public method
