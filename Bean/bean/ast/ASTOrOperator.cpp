#include "ASTOrOperator.h"
#include "../env/Boolean.h"
#include "../env/Null.h"
#include "../env/Object_.h"

//public method---
ASTOrOperator::ASTOrOperator() {
}

ASTOrOperator::~ASTOrOperator() {
}

Object_ * ASTOrOperator::eval() {
	buffer_begin();
	Boolean* left = getLeft()->eval()->asBoolean();
	Boolean* right = getRight()->eval()->asBoolean();
	Object_* retVal = Null::getInstance();
	if (left != nullptr && right != nullptr) {
		retVal = Boolean:: or (left, right);
	}
	buffer_end();
	return retVal;
}

std::string ASTOrOperator::format() const {
	return "|";
}
IMPL_MAKE_SHARED_0_CPP(ASTOrOperator)
//---public method
