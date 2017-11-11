#include "ASTSubAssignOperator.h"
#include "ASTPointer.h"
#include "../env/Object_.h"

//public method---
ASTSubAssignOperator::ASTSubAssignOperator() {
}

ASTSubAssignOperator::~ASTSubAssignOperator() {
}

Object_ * ASTSubAssignOperator::eval() {
	Object_* ptr = getPointer()->getReference()->getValue();
	return ptr->sub(getFactor()->eval());
}
IMPL_MAKE_SHARED_0_CPP(ASTSubAssignOperator)
//---public method
