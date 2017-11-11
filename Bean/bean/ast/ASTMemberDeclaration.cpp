#include "ASTMemberDeclaration.h"

//public method---
ASTMemberDeclaration::ASTMemberDeclaration() {
}

void ASTMemberDeclaration::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTMemberDeclaration::getName()  const {
	return this->name;
}

void ASTMemberDeclaration::setModifier(std::shared_ptr<ASTModifier> modifier) {
	this->modifier = modifier;
}

std::shared_ptr<ASTModifier> ASTMemberDeclaration::getModifier() const {
	return this->modifier;
}
//---public method

//protected method---
ASTMemberDeclaration::~ASTMemberDeclaration() {
}
//---protected method