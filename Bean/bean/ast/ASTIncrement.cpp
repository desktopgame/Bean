#include "ASTIncrement.h"
#include "../env/Object_.h"

//public method---
ASTIncrement::ASTIncrement() {
}

ASTIncrement::~ASTIncrement() {
}

std::string ASTIncrement::format() const {
	return "++";
}
IMPL_MAKE_SHARED_0_CPP(ASTIncrement)
//---public method


//protected method---
void ASTIncrement::edit(Object_ * src) {
	src->increment();
}

Object_ * ASTIncrement::lazy(Object_ * target, Object_ * one) {
	return target;
}
//---protected method