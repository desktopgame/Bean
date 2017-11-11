#include "ASTContinueStatement.h"

//public method---
ASTContinueStatement::ASTContinueStatement() {
}

ASTContinueStatement::~ASTContinueStatement() {
}

std::string ASTContinueStatement::format() const {
	return "continue";
}

void ASTContinueStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTContinueStatement));
	visitor->exit(SHARED_FROM_THIS(ASTContinueStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTContinueStatement)
//---public method
