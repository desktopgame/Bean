#include "ASTMethodDeclaration.h"

//public method---
ASTMethodDeclaration::ASTMethodDeclaration() {
	this->simple = false;
}

ASTMethodDeclaration::~ASTMethodDeclaration() {
	parameters.clear();
}

void ASTMethodDeclaration::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTMethodDeclaration::getBody() const {
	return this->body;
}

void ASTMethodDeclaration::addParameter(std::shared_ptr<ASTParameter> parameter) {
	this->parameters.push_back(parameter);
}

std::shared_ptr<ASTParameter> ASTMethodDeclaration::getParameterAt(int index) const {
	return this->parameters.at(index);
}

int ASTMethodDeclaration::getParameterCount() const {
	return parameters.size();
}

void ASTMethodDeclaration::setSimple(bool isSimple) {
	this->simple = isSimple;
}

bool ASTMethodDeclaration::isSimple() const {
	return this->simple;
}

std::string ASTMethodDeclaration::format() const {
	return "method";
}

void ASTMethodDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTMethodDeclaration));
	visitor->exit(SHARED_FROM_THIS(ASTMethodDeclaration));
}
IMPL_MAKE_SHARED_0_CPP(ASTMethodDeclaration)
//---public method
