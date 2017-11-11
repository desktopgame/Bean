#include "ASTDynFieldDeclaration.h"
#include "ASTName.h"
//public method---
ASTDynFieldDeclaration::ASTDynFieldDeclaration() {
}

ASTDynFieldDeclaration::~ASTDynFieldDeclaration() {
}

void ASTDynFieldDeclaration::setInvoker(std::shared_ptr<ASTFactor> invoker) {
	this->invoker = invoker;
}

std::shared_ptr<ASTFactor> ASTDynFieldDeclaration::getInvoker() const {
	return this->invoker;
}

void ASTDynFieldDeclaration::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTDynFieldDeclaration::getName() const {
	return this->name;
}

void ASTDynFieldDeclaration::setValue(std::shared_ptr<ASTFactor> value) {
	this->value = value;
}

std::shared_ptr<ASTFactor> ASTDynFieldDeclaration::getValue() const {
	return this->value;
}

std::string ASTDynFieldDeclaration::format() const {
	return "dyn field:" + getName()->getCString();
}

void ASTDynFieldDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTDynFieldDeclaration));
	visitor->exit(SHARED_FROM_THIS(ASTDynFieldDeclaration));
}
IMPL_MAKE_SHARED_0_CPP(ASTDynFieldDeclaration)
//---public method