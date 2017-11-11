#include "ASTEnumDeclaration.h"
#include "ASTEnumItemDeclaration.h"
#include "ASTName.h"
#include "../util/STL.h"

//public method---
ASTEnumDeclaration::ASTEnumDeclaration() {
	this->enumItemList = std::vector<std::shared_ptr<ASTEnumItemDeclaration>>();
}

ASTEnumDeclaration::~ASTEnumDeclaration() {
	enumItemList.clear();
}

void ASTEnumDeclaration::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTEnumDeclaration::getName()  const {
	return this->name;
}

void ASTEnumDeclaration::addEnumItem(std::shared_ptr<ASTEnumItemDeclaration> item) {
	this->enumItemList.push_back(item);
}

std::shared_ptr<ASTEnumItemDeclaration> ASTEnumDeclaration::getEnumItemAt(int index) const {
	return enumItemList.at(index);
}

void ASTEnumDeclaration::removeEnumItemAt(int index) {
	enumItemList.erase(enumItemList.begin() + index);
}

int ASTEnumDeclaration::getEnumItemCount() const {
	return enumItemList.size();
}

std::string ASTEnumDeclaration::format() const {
	return "enum";
}

void ASTEnumDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTEnumDeclaration));
	visitor->exit(SHARED_FROM_THIS(ASTEnumDeclaration));
}
IMPL_MAKE_SHARED_0_CPP(ASTEnumDeclaration)
//---public method
