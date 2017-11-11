#include "ASTParameter.h"

//public method---
ASTParameter::ASTParameter(std::shared_ptr<ASTName> name) {
	this->name = name;
}

ASTParameter::~ASTParameter() {
}

std::shared_ptr<ASTName> ASTParameter::getName() const {
	return this->name;
}

std::string ASTParameter::format() const {
	std::wstring wstr = getName()->getCWString();
	std::string str = std::string(wstr.begin(), wstr.end());
	return "param: " + str;
}
IMPL_MAKE_SHARED_1_CPP(ASTParameter, std::shared_ptr<ASTName>)
//---public method
