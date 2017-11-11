#include "ASTConstructorDeclaration.h"
//public method---
ASTConstructorDeclaration::ASTConstructorDeclaration() {
}

ASTConstructorDeclaration::~ASTConstructorDeclaration() {
}

void ASTConstructorDeclaration::setChain(std::shared_ptr<ASTConstructorChain> chain) {
	this->chain = chain;
}

std::shared_ptr<ASTConstructorChain> ASTConstructorDeclaration::getChain() {
	return this->chain;
}
IMPL_MAKE_SHARED_0_CPP(ASTConstructorDeclaration)
//---public method