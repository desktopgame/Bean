#include "ASTDynMethodDeclaration.h"
#include "ASTName.h"
//public method---
ASTDynMethodDeclaration::ASTDynMethodDeclaration() {
}

ASTDynMethodDeclaration::~ASTDynMethodDeclaration() {
}

void ASTDynMethodDeclaration::setInvoker(std::shared_ptr<ASTFactor> invoker) {
	this->invoker = invoker;
}

std::shared_ptr<ASTFactor> ASTDynMethodDeclaration::getInvoker() const {
	return this->invoker;
}

void ASTDynMethodDeclaration::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTDynMethodDeclaration::getName() const {
	return this->name;
}

void ASTDynMethodDeclaration::setLambda(std::shared_ptr<ASTLambdaDeclaration> lambda) {
	this->lambda = lambda;
}

std::shared_ptr<ASTLambdaDeclaration> ASTDynMethodDeclaration::getLambda() const {
	return this->lambda;
}

std::string ASTDynMethodDeclaration::format() const {
	return "dyn method:" + getName()->getCString();
}

void ASTDynMethodDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTDynMethodDeclaration));
	visitor->exit(SHARED_FROM_THIS(ASTDynMethodDeclaration));
}
IMPL_MAKE_SHARED_0_CPP(ASTDynMethodDeclaration)
//---public method