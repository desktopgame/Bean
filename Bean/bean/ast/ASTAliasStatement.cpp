#include "ASTAliasStatement.h"
#include "ASTName.h"
//public method---
ASTAliasStatement::ASTAliasStatement() {
}

ASTAliasStatement::~ASTAliasStatement() {
}

void ASTAliasStatement::setOldName(std::shared_ptr<ASTName> oldName) {
	this->oldName = oldName;
}

std::shared_ptr<ASTName> ASTAliasStatement::getOldName() const {
	return this->oldName;
}

void ASTAliasStatement::setNewName(std::shared_ptr<ASTName> newName) {
	this->newName = newName;
}

std::shared_ptr<ASTName> ASTAliasStatement::getNewName() const {
	return this->newName;
}

std::string ASTAliasStatement::format() const {
	return "alias " + getOldName()->getCString() + " : " + getNewName()->getCString();
}

void ASTAliasStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTAliasStatement));
	visitor->exit(SHARED_FROM_THIS(ASTAliasStatement));
}
IMPL_MAKE_SHARED_0_CPP(ASTAliasStatement)
//---public method