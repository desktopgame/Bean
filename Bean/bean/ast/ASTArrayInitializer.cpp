#include "ASTArrayInitializer.h"
#include "../env/Object_.h"
#include "../env/user/UserArray.h"

//public method---
ASTArrayInitializer::ASTArrayInitializer() {
	this->elems = std::vector<ASTFactorSPtr>();
}

ASTArrayInitializer::~ASTArrayInitializer() {
	elems.clear();
}

void ASTArrayInitializer::addFactor(ASTFactorSPtr factor) {
	elems.push_back(factor);
}

ASTFactorSPtr ASTArrayInitializer::getFactorAt(int index) const {
	return elems.at(index);
}

int ASTArrayInitializer::getFactorCount() const {
	return elems.size();
}

Object_ * ASTArrayInitializer::eval() {
	UserArray* arr = new UserArray();
	arr->alloc(elems.size());
	for (int i = 0; i < elems.size(); i++) {
		Object_* elem = elems.at(i)->eval();
		arr->set(i, elem);
	}
	return arr;
}

std::string ASTArrayInitializer::format() const {
	return "array";
}
IMPL_MAKE_SHARED_0_CPP(ASTArrayInitializer)
//---public method
