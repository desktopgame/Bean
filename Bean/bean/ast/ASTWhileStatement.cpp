#include "ASTWhileStatement.h"

//public method---
ASTWhileStatement::ASTWhileStatement() {
}

ASTWhileStatement::~ASTWhileStatement() {
}

void ASTWhileStatement::setFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

std::shared_ptr<ASTFactor> ASTWhileStatement::getFactor() const {
	return this->factor;
}

void ASTWhileStatement::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTWhileStatement::getBody() const {
	return this->body;
}

std::string ASTWhileStatement::format() const {
	return "while";
}

void ASTWhileStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTWhileStatement));
	visitor->exit(SHARED_FROM_THIS(ASTWhileStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTWhileStatement)
//---public method
