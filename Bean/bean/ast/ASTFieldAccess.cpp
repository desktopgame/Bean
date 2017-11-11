#include "ASTFieldAccess.h"
#include "ASTName.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Exception.h"
#include "../env/Field.h"
#include "../env/IncludeManager.h"
#include "../env/Null.h"
#include "../env/Object_.h"
#include "../env/pointer/FieldPointer.h"

//public method---
ASTFieldAccess::ASTFieldAccess() {
}

ASTFieldAccess::~ASTFieldAccess() {
}

void ASTFieldAccess::setParent(std::shared_ptr<ASTFactor> parent) {
	this->parent = parent;
}

std::shared_ptr<ASTFactor> ASTFieldAccess::getParent() const {
	return parent;
}

void ASTFieldAccess::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTFieldAccess::getName() const {
	return name;
}

PointerSPtr ASTFieldAccess::getReference() {
	if (this->pointee == nullptr) {
		this->pointee = std::make_shared<FieldPointer>(SHARED_FROM_THIS(ASTFieldAccess));
	}
	return this->pointee;
}

Object_ * ASTFieldAccess::eval() {
	Object_* ret = getReference()->getValue();
	return ret;
}

std::string ASTFieldAccess::format() const {
	return getParent()->format() + "." + getName()->getCString();
}
IMPL_MAKE_SHARED_0_CPP(ASTFieldAccess)
//---public method

//protected method---
Object_ * ASTFieldAccess::evalThrow() {
	Object_* ret = getReference()->getValue();
	if (ret == nullptr) {
		Exception::throw_e_simple("api.exc.NoFieldError", "フィールドが見つかりません。:" + format());
	}
	return ret;
}
//---protected method
