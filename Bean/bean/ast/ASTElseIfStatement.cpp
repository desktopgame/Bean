#include "ASTElseIfStatement.h"
#include "ASTBody.h"
#include "ASTFactor.h"
#include "ASTNode.h"

//public method---
ASTElseIfStatement::ASTElseIfStatement() {
}

ASTElseIfStatement::~ASTElseIfStatement() {
}

std::string ASTElseIfStatement::format() const {
	return "elseif";
}

void ASTElseIfStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTElseIfStatement));
	visitor->exit(SHARED_FROM_THIS(ASTElseIfStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTElseIfStatement)
//---public method
