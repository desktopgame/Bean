#include "ASTMulAssignOperator.h"
#include "ASTPointer.h"
#include "../env/Object_.h"

//public method---
ASTMulAssignOperator::ASTMulAssignOperator() {
}

ASTMulAssignOperator::~ASTMulAssignOperator() {
}

Object_ * ASTMulAssignOperator::eval() {
	Object_* ptr = getPointer()->getReference()->getValue();
	return ptr->mul (getFactor()->eval());
}
IMPL_MAKE_SHARED_0_CPP(ASTMulAssignOperator)
//---public method
