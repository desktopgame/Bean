#include "ASTBreakStatement.h"

//public method---
ASTBreakStatement::ASTBreakStatement() {
}

ASTBreakStatement::~ASTBreakStatement() {
}

std::string ASTBreakStatement::format() const {
	return "break";
}

void ASTBreakStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTBreakStatement));
	visitor->exit(SHARED_FROM_THIS(ASTBreakStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTBreakStatement)
//---public method
