#include "ASTIfStatement.h"
#include "ASTBody.h"
#include "ASTElseIfStatement.h"
#include "ASTElseStatement.h"
#include "ASTFactor.h"
#include "ASTNode.h"

//public method---
ASTIfStatement::ASTIfStatement() {
}

ASTIfStatement::~ASTIfStatement() {
	elseIfStatements.clear();
}

void ASTIfStatement::addElseIf(std::shared_ptr<ASTElseIfStatement> elseIfStatement) {
	this->elseIfStatements.push_back(elseIfStatement);
}

std::shared_ptr<ASTElseIfStatement> ASTIfStatement::getElseIfAt(int index) const {
	return elseIfStatements.at(index);
}

int ASTIfStatement::getElseIfCount() const {
	return elseIfStatements.size();
}

void ASTIfStatement::setElse(std::shared_ptr<ASTElseStatement> elseStatement) {
	this->elseStatement = elseStatement;
}

std::shared_ptr<ASTElseStatement> ASTIfStatement::getElse() const {
	return this->elseStatement;
}

std::string ASTIfStatement::format() const {
	return "if";
}

void ASTIfStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTIfStatement));
	visitor->exit(SHARED_FROM_THIS(ASTIfStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTIfStatement)
//---public method
