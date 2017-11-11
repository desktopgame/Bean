#include "ASTClassDeclaration.h"

//public method---
ASTClassDeclaration::ASTClassDeclaration() {
}

ASTClassDeclaration::~ASTClassDeclaration() {
	fields.clear();
	methods.clear();
}

void ASTClassDeclaration::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTClassDeclaration::getName() const {
	return this->name;
}

void ASTClassDeclaration::setSuperClass(std::shared_ptr<ASTName> superClass) {
	this->superClass = superClass;
}

std::shared_ptr<ASTName> ASTClassDeclaration::getSuperClass() const {
	return this->superClass;
}

void ASTClassDeclaration::addField(std::shared_ptr<ASTFieldDeclaration> field) {
	fields.push_back(field);
}

std::shared_ptr<ASTFieldDeclaration> ASTClassDeclaration::getFieldAt(int index) {
	return this->fields.at(index);
}

int ASTClassDeclaration::getFieldCount() {
	return fields.size();
}

void ASTClassDeclaration::addMethod(std::shared_ptr<ASTMethodDeclaration> method) {
	methods.push_back(method);
}

std::shared_ptr<ASTMethodDeclaration> ASTClassDeclaration::getMethodAt(int index) const {
	return methods.at(index);
}

int ASTClassDeclaration::getMethodCount() const {
	return methods.size();
}

std::string ASTClassDeclaration::format() const {
	return "class declaration";
}

void ASTClassDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTClassDeclaration));
	for (int i = 0; i < getFieldCount(); i++) {
		getFieldAt(i)->accept(visitor);
	}
	for (int i = 0; i < getMethodCount(); i++) {
		getMethodAt(i)->accept(visitor);
	}
	visitor->exit(SHARED_FROM_THIS(ASTClassDeclaration));
}
IMPL_MAKE_SHARED_0_CPP(ASTClassDeclaration)
//---public method

