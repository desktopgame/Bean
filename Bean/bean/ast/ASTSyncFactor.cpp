#include "ASTSyncFactor.h"
#include "../env/gc/Heap.h"

//public method---
ASTSyncFactor::ASTSyncFactor(std::shared_ptr<ASTFactor> factor) {
	this->factor = factor;
}

ASTSyncFactor::~ASTSyncFactor() {
}

ClassSPtr ASTSyncFactor::getBaseLine(ClassSPtr classz) {
	return factor->getBaseLine(classz);
}

Object_ * ASTSyncFactor::eval() {
	Heap::getInstance()->enter();
	Object_* r = factor->eval();
	Heap::getInstance()->exit();
	return r;
}

bool ASTSyncFactor::isStaticReceiver() {
	return factor->isStaticReceiver();
}

std::string ASTSyncFactor::getStaticClassName() {
	return factor->getStaticClassName();
}

void ASTSyncFactor::accept(ASTVisitor * visitor) {
	factor->accept(visitor);
}
IMPL_MAKE_SHARED_1_CPP(ASTSyncFactor, std::shared_ptr<ASTFactor>)
//---public method