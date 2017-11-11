#include "ASTReturnStatement.h"

//public method---
ASTReturnStatement::ASTReturnStatement() {
}

ASTReturnStatement::~ASTReturnStatement() {
}

void ASTReturnStatement::setFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

std::shared_ptr<ASTFactor> ASTReturnStatement::getFactor() const {
	return this->factor;
}

std::string ASTReturnStatement::format() const {
	return "return";
}

void ASTReturnStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTReturnStatement));
	visitor->exit(SHARED_FROM_THIS(ASTReturnStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTReturnStatement)
//---public method
