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
	//ASTNumericと同様の理由により、遅延初期化しています。
	//
	if (value == nullptr) {
		this->value = String::ownedString(&src);
		//
		//ASTNumericと同様の理由により、GCの対象になったらNULLを設定します。
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
