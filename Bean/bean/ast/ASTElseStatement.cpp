#include "ASTElseStatement.h"

//public method---
ASTElseStatement::ASTElseStatement() {
}

ASTElseStatement::~ASTElseStatement() {
}

void ASTElseStatement::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTElseStatement::getBody() const {
	return this->body;
}

std::string ASTElseStatement::format() const {
	return "else";
}

void ASTElseStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTElseStatement));
	visitor->exit(SHARED_FROM_THIS(ASTElseStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTElseStatement)
//---public method
