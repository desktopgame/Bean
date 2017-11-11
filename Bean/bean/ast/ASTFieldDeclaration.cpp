#include "ASTFieldDeclaration.h"
#include "ASTFactor.h"

//public method---
ASTFieldDeclaration::ASTFieldDeclaration() {
	this->defaultValue = nullptr;
	this->setMethodName = nullptr;
	this->getMethodName = nullptr;
}

ASTFieldDeclaration::~ASTFieldDeclaration() {
}

std::string ASTFieldDeclaration::format() const {
	return "field: " + getName()->getCString();
}

void ASTFieldDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTFieldDeclaration));
	accept_(visitor, getName());
	accept_(visitor, getModifier());
	visitor->exit(SHARED_FROM_THIS(ASTFieldDeclaration));
}

void ASTFieldDeclaration::setDefaultValue(std::shared_ptr<ASTFactor> defaultValue) {
	this->defaultValue = defaultValue;
}

std::shared_ptr<ASTFactor> ASTFieldDeclaration::getDefaultValue() const {
	return defaultValue;
}

void ASTFieldDeclaration::setSetMethodName(std::shared_ptr<ASTName> setMethodName) {
	this->setMethodName = setMethodName;
}

std::shared_ptr<ASTName> ASTFieldDeclaration::getSetMethodName() const {
	return setMethodName;
}

void ASTFieldDeclaration::setGetMethodName(std::shared_ptr<ASTName> getMethodName) {
	this->getMethodName = getMethodName;
}

std::shared_ptr<ASTName> ASTFieldDeclaration::getGetMethodName() const {
	return getMethodName;
}
IMPL_MAKE_SHARED_0_CPP(ASTFieldDeclaration)
//---public method

