#include "ASTName.h"

//public method---
ASTName::ASTName(const BString& string) {
	this->string = string;
}

ASTName::~ASTName() {
}

BString ASTName::getBString() const {
	return string;
}

std::string ASTName::getCString() const {
#ifdef BTEXT_MULTI
	return string;
#else
	return std::string(string.begin(), string.end());
#endif // BTEXT_MULTI
}

std::wstring ASTName::getCWString() const {
#ifdef BTEXT_WIDE
	return string;
#else
	return std::wstring(string.begin(), string.end());
#endif // BTEXT_WIDE
}

std::string ASTName::format() const {
	std::wstring src = getCWString();
	return "name:" + std::string(src.begin(), src.end());
}

#ifdef BTEXT_WIDE
IMPL_MAKE_SHARED_1_CPP(ASTName, std::string)
#endif // BTEXT_WIDE
IMPL_MAKE_SHARED_1_CPP(ASTName, BString)
//---public method
