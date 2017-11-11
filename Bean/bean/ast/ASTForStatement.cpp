#include "ASTForStatement.h"

//public method---
ASTForStatement::ASTForStatement() {
}

ASTForStatement::~ASTForStatement() {
}

void ASTForStatement::setInitialize(std::shared_ptr<ASTNode> initialize) {
	this->initialize = initialize;
}

std::shared_ptr<ASTNode> ASTForStatement::getInitialize() const {
	return this->initialize;
}

void ASTForStatement::setFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

std::shared_ptr<ASTFactor> ASTForStatement::getFactor() const {
	return this->factor;
}

void ASTForStatement::setUpdate(std::shared_ptr<ASTNode> update) {
	this->update = update;
}

std::shared_ptr<ASTNode> ASTForStatement::getUpdate() const {
	return this->update;
}

void ASTForStatement::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTForStatement::getBody() const {
	return this->body;
}

std::string ASTForStatement::format() const {
	return "for";
}

void ASTForStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTForStatement));
	visitor->exit(SHARED_FROM_THIS(ASTForStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTForStatement)
//---public method
