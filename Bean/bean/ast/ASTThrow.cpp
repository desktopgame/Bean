#include "ASTThrow.h"
#include "ASTFactor.h"

//public method---
ASTThrow::ASTThrow() {
}

ASTThrow::~ASTThrow() {
}

void ASTThrow::setFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

std::shared_ptr<ASTFactor> ASTThrow::getFactor() const {
	return factor;
}

void ASTThrow::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTThrow));
	visitor->exit(SHARED_FROM_THIS(ASTThrow));
}

std::string ASTThrow::format() const {
	return "throw";
}
IMPL_MAKE_SHARED_0_CPP(ASTThrow)
//---public method
