#include "ASTIfCauseStatement.h"

//public method---
ASTIfCauseStatement::ASTIfCauseStatement() {
}

ASTIfCauseStatement::~ASTIfCauseStatement() {
}

void ASTIfCauseStatement::setFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

std::shared_ptr<ASTFactor> ASTIfCauseStatement::getFactor() const {
	return this->factor;
}

void ASTIfCauseStatement::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTIfCauseStatement::getBody() const {
	return this->body;
}
//---public method
