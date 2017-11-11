#include "ASTVariableDeclaration.h"

//public method---
ASTVariableDeclaration::ASTVariableDeclaration() {
}

ASTVariableDeclaration::~ASTVariableDeclaration() {
}

void ASTVariableDeclaration::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTVariableDeclaration::getName() const {
	return this->name;
}

void ASTVariableDeclaration::setFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

std::shared_ptr<ASTFactor> ASTVariableDeclaration::getFactor() const {
	return this->factor;
}

std::string ASTVariableDeclaration::format() const {
	return "var";
}

void ASTVariableDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTVariableDeclaration));
	visitor->exit(SHARED_FROM_THIS(ASTVariableDeclaration));
}
IMPL_MAKE_SHARED_0_CPP(ASTVariableDeclaration)
//---public method
