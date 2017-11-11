#include "ASTBinaryOperator.h"
#include "ASTNode.h"

//public method---
ASTBinaryOperator::ASTBinaryOperator() {
}

ASTBinaryOperator::~ASTBinaryOperator() {
}

void ASTBinaryOperator::setLeft(ASTFactorSPtr left) {
	this->left = left;
}

ASTFactorSPtr ASTBinaryOperator::getLeft()  const {
	return this->left;
}

void ASTBinaryOperator::setRight(ASTFactorSPtr right) {
	this->right = right;
}

ASTFactorSPtr ASTBinaryOperator::getRight()  const {
	return this->right;
}

void ASTBinaryOperator::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTBinaryOperator));
	visitor->exit(SHARED_FROM_THIS(ASTBinaryOperator));
}
//IMPL_MAKE_SHARED_0_CPP(ASTBinaryOperator)
//---public method

