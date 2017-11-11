#include "ASTModifier.h"

//public method---
ASTModifier::ASTModifier(Modifier mod) {
	this->mod = mod;
}

ASTModifier::~ASTModifier() {
}

std::string ASTModifier::format() const {
	return mod.getString();
}

Modifier ASTModifier::getValue() const {
	return this->mod;
}
IMPL_MAKE_SHARED_1_CPP(ASTModifier, Modifier)
//---public method
