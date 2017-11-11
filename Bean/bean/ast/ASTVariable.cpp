#include "ASTVariable.h"
#include "ASTName.h"
#include "../Debug.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/CodeBlock.h"
#include "../env/Exception.h"
#include "../env/Object_.h"
#include "../util/TimeSpan.h"
#include "../env/pointer/VariablePointer.h"

//public method---
ASTVariable::ASTVariable(std::shared_ptr<ASTName> name) {
	this->name = name;
}

ASTVariable::~ASTVariable() {
}

std::shared_ptr<ASTName> ASTVariable::getName() const {
	return this->name;
}

std::string ASTVariable::format() const {
	std::wstring wstr = getName()->getCWString();
	return "obj: " + std::string(wstr.begin(), wstr.end());
}

Object_ * ASTVariable::eval() {
	Object_* ret = getReference()->getValue();
	return ret;
}

PointerSPtr ASTVariable::getReference() {
	if (this->pointee == nullptr) {
		this->pointee = std::make_shared<VariablePointer>(SHARED_FROM_THIS(ASTVariable));
	}
	return this->pointee;
}

bool ASTVariable::isStaticReceiver() {
	return true;
}

std::string ASTVariable::getStaticClassName() {
	return getName()->getCString();
}
IMPL_MAKE_SHARED_1_CPP(ASTVariable, std::shared_ptr<ASTName>)
//---public method


//protected method---
Object_ * ASTVariable::evalThrow() {
	Object_* ret = getReference()->getValue();
	if (ret == nullptr) {
		Exception::throw_e_simple("api.exc.NoNameError", "•Ï”‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñB:" + format());
	}
	return ret;
}
//---protected method
