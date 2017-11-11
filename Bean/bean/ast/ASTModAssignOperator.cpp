#include "ASTModAssignOperator.h"
#include "ASTPointer.h"
#include "../env/Object_.h"

//public method---
ASTModAssignOperator::ASTModAssignOperator() {
}

ASTModAssignOperator::~ASTModAssignOperator() {
}

Object_ * ASTModAssignOperator::eval() {
	Object_* ptr = getPointer()->getReference()->getValue();
	return ptr->mod(getFactor()->eval());
}
IMPL_MAKE_SHARED_0_CPP(ASTModAssignOperator)
//---public method
