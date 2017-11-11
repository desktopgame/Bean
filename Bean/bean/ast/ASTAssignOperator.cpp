#include "ASTAssignOperator.h"
#include "ASTFactor.h"
#include "ASTName.h"
#include "ASTPointer.h"
#include "../env/gc/Heap.h"

//public method---
ASTAssignOperator::ASTAssignOperator() {
}

ASTAssignOperator::~ASTAssignOperator() {
}

void ASTAssignOperator::setPointer(std::shared_ptr<ASTPointer> pointer) {
	this->pointer = pointer;
}

std::shared_ptr<ASTPointer> ASTAssignOperator::getPointer() const {
	return pointer;
}

void ASTAssignOperator::setFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

std::shared_ptr<ASTFactor> ASTAssignOperator::getFactor() const {
	return factor;
}

std::string ASTAssignOperator::format() const {
	return "=";
}

Object_ * ASTAssignOperator::eval() {
//	GCSystem::getInstance()->lock();
//	buffer_rankUp();
	Object_* ref = getFactor()->eval();
//	buffer_rankDown();
//	GCSystem::getInstance()->unlock();
	return ref;
}
IMPL_MAKE_SHARED_0_CPP(ASTAssignOperator)
//---public method
