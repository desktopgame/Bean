#include "ASTUnaryOperator.h"
#include "../env/Boolean.h"
#include "../env/Object_.h"

//public method---
ASTUnaryOperator::ASTUnaryOperator() {
}

void ASTUnaryOperator::setCondition(std::shared_ptr<ASTFactor> condition) {
	this->condition = condition;
}

std::shared_ptr<ASTFactor> ASTUnaryOperator::getCondition() const {
	return condition;
}

void ASTUnaryOperator::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTUnaryOperator));
	visitor->exit(SHARED_FROM_THIS(ASTUnaryOperator));
}
//---public method

//protected method---
ASTUnaryOperator::~ASTUnaryOperator() {
}
//---protected method
