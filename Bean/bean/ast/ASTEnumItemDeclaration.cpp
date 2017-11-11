#include "ASTEnumItemDeclaration.h"
#include "ASTFactor.h"
#include "ASTName.h"

//public method---
ASTEnumItemDeclaration::ASTEnumItemDeclaration() {
}

ASTEnumItemDeclaration::~ASTEnumItemDeclaration() {
}

void ASTEnumItemDeclaration::setValue(std::shared_ptr<ASTFactor> value) {
	this->value = value;
}

std::shared_ptr<ASTFactor> ASTEnumItemDeclaration::getValue() const {
	return this->value;
}

void ASTEnumItemDeclaration::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTEnumItemDeclaration::getName() const {
	return this->name;
}
IMPL_MAKE_SHARED_0_CPP(ASTEnumItemDeclaration)
//---public method
