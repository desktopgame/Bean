#include "ASTString.h"
#include "../env/Null.h"
#include "../env/Object_.h"
#include "../util/Memory.h"
#include "../env/gc/Block.h"
#include "../env/gc/GCLock.h"
#include "../env/gc/Heap.h"

//public method---
ASTString::ASTString(const BString& src) {
	this->src = src;
	this->ref = nullptr;
	this->value = NULL;
}

ASTString::~ASTString() {
	if (value != NULL) {
		value->getState()->removeStrongReference(this);
	}
}

std::string ASTString::format() const {
	std::string s = std::string(src.begin(), src.end());
	return "string:" + s;
}

String * ASTString::getValue() {
	GCLock gcLock = GCLock();
	//
	//ASTNumeric�Ɠ��l�̗��R�ɂ��A�x�����������Ă��܂��B
	//
	if (value == nullptr) {
		this->value = String::ownedString(&src);
		//
		//ASTNumeric�Ɠ��l�̗��R�ɂ��AGC�̑ΏۂɂȂ�����NULL��ݒ肵�܂��B
		value->getState()->addStrongReference(this);
	}
	return this->value;
}

Object_ * ASTString::eval() {
	return getValue();
}

#ifdef BTEXT_WIDE
IMPL_MAKE_SHARED_1_CPP(ASTString, std::string)
#endif // BTEXT_WIDE
IMPL_MAKE_SHARED_1_CPP(ASTString, BString)
//---public method
