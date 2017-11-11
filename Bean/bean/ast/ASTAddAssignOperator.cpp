#include "ASTAddAssignOperator.h"
#include "ASTPointer.h"
#include "../env/Object_.h"
#include "../env/gc/Heap.h"

//public method---
ASTAddAssignOperator::ASTAddAssignOperator() {
}

ASTAddAssignOperator::~ASTAddAssignOperator() {
}

Object_ * ASTAddAssignOperator::eval() {
	buffer_begin();
	Object_* ptr = getPointer()->getReference()->getValue();
	Object_* retRef = ptr->add(getFactor()->eval());
	buffer_end();
	return retRef;
}
IMPL_MAKE_SHARED_0_CPP(ASTAddAssignOperator)
//---public method
