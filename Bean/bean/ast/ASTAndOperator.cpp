#include "ASTAndOperator.h"
#include "../env/Boolean.h"
#include "../env/Null.h"
#include "../env/Object_.h"

//public method---
ASTAndOperator::ASTAndOperator() {
}

ASTAndOperator::~ASTAndOperator() {
}

Object_ * ASTAndOperator::eval() {
	buffer_begin();
	Boolean* left = getLeft()->eval()->asBoolean();
	Boolean* right = getRight()->eval()->asBoolean();
	Object_* retVal = Null::getInstance();
	if (left != nullptr && right != nullptr) {
		retVal = Boolean:: and (left, right);
	}
	buffer_end();
	return retVal;
}

std::string ASTAndOperator::format() const {
	return "&";
}
IMPL_MAKE_SHARED_0_CPP(ASTAndOperator)
//---public method
