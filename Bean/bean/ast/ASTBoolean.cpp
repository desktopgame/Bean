#include "ASTBoolean.h"
#include "../env/Boolean.h"
#include "../env/gc/Heap.h"

//public method---
ASTBoolean::ASTBoolean(bool b) {
	this->b = b;
}

ASTBoolean::~ASTBoolean() {
}

Object_ * ASTBoolean::eval() {
	return Boolean::get(b);
}

std::string ASTBoolean::format() const {
	return b ? "true" : "false";
}
IMPL_MAKE_SHARED_1_CPP(ASTBoolean, bool)
//---public method
