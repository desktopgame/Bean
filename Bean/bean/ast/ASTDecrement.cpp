#include "ASTDecrement.h"
#include "../env/Object_.h"

//public method---
ASTDecrement::ASTDecrement() {
}

ASTDecrement::~ASTDecrement() {
}

std::string ASTDecrement::format() const {
	return "--";
}
IMPL_MAKE_SHARED_0_CPP(ASTDecrement)
//---public method

//protected method---
Object_ * ASTDecrement::lazy(Object_ * target, Object_ * one) {
	return target;
}

void ASTDecrement::edit(Object_ * src) {
	src->decrement();
}
//---protected method