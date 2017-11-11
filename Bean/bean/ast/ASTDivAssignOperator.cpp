#include "ASTDivAssignOperator.h"
#include "ASTPointer.h"
#include "../env/Object_.h"

//public method---
ASTDivAssignOperator::ASTDivAssignOperator() {
}

ASTDivAssignOperator::~ASTDivAssignOperator() {
}

Object_ * ASTDivAssignOperator::eval() {
	Object_* ptr = getPointer()->getReference()->getValue();
	return ptr->div(getFactor()->eval());
}
IMPL_MAKE_SHARED_0_CPP(ASTDivAssignOperator)
//---public method
