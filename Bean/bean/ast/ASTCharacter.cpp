#include "ASTCharacter.h"
#include "../env/Character.h"
#include "../env/gc/GCLock.h"
#include "../env/gc/Heap.h"

//public method---
ASTCharacter::ASTCharacter(BChar wc) {
	this->wc = wc;
	this->value = nullptr;
}

ASTCharacter::~ASTCharacter() {
	if (value != NULL) {
		value->getState()->removeStrongReference(this);
	}
}

Character * ASTCharacter::getValue() {
	GCLock gcLock = GCLock();
	if (value == nullptr) {
		this->value = new Character(wc);
		//
		//ASTNumericと同様の理由により、GCの対象になったらNULLを設定します。
		//value->addDeleteListener(this);
		value->getState()->addStrongReference(this);
	}
	return value;
}

Object_ * ASTCharacter::eval() {
	return getValue();
}

std::string ASTCharacter::format() const {
	return "character: " + static_cast<char>(wc);
}
#ifdef BTEXT_WIDE
IMPL_MAKE_SHARED_1_CPP(ASTCharacter, char)
#endif // BTEXT_WIDE
IMPL_MAKE_SHARED_1_CPP(ASTCharacter, BChar)
//---public method
