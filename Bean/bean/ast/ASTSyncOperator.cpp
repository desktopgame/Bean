#include "ASTSyncOperator.h"

//public method---
ASTSyncOperator::ASTSyncOperator(std::shared_ptr<ASTOperator> op) {
	this->op = op;
}

ASTSyncOperator::~ASTSyncOperator() {
}

ClassSPtr ASTSyncOperator::getBaseLine(ClassSPtr classz) {
	return op->getBaseLine(classz);
}

Object_ * ASTSyncOperator::eval() {
	return op->eval();
}

bool ASTSyncOperator::isStaticReceiver() {
	return op->isStaticReceiver();
}

std::string ASTSyncOperator::getStaticClassName() {
	return op->getStaticClassName();
}

void ASTSyncOperator::accept(ASTVisitor * visitor) {
	op->accept(visitor);
}
IMPL_MAKE_SHARED_1_CPP(ASTSyncOperator, std::shared_ptr<ASTOperator>)
//---public method