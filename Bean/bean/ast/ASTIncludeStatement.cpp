#include "ASTIncludeStatement.h"

//public method---
ASTIncludeStatement::ASTIncludeStatement() {
}

ASTIncludeStatement::~ASTIncludeStatement() {
}

void ASTIncludeStatement::setPath(std::shared_ptr<ASTName> path) {
	this->path = path;
}

std::shared_ptr<ASTName> ASTIncludeStatement::getPath() const {
	return this->path;
}

std::string ASTIncludeStatement::format() const {
	return "use";
}

void ASTIncludeStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTIncludeStatement));
	visitor->exit(SHARED_FROM_THIS(ASTIncludeStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTIncludeStatement)
//---public method
