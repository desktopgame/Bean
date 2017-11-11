#include "ASTAndAndOperator.h"
#include "../env/Boolean.h"
#include "../env/Null.h"
#include "../env/Object_.h"

//public method---
ASTAndAndOperator::ASTAndAndOperator() {
}

ASTAndAndOperator::~ASTAndAndOperator() {
}

Object_ * ASTAndAndOperator::eval() {
	buffer_begin();
	Object_* retVal = evalImpl();
	buffer_end();
	return retVal;
}

std::string ASTAndAndOperator::format() const {
	return "&&";
}
IMPL_MAKE_SHARED_0_CPP(ASTAndAndOperator)
//---public method

//private method---
Object_ * ASTAndAndOperator::evalImpl() {
	//‚Ç‚¿‚ç‚©‚ªfalse‚È‚ç‚à‚¤•Ð•û‚Í•]‰¿‚µ‚È‚¢
	Object_* objLeft = getLeft()->eval();
	Boolean* left = objLeft->asBoolean();
	if (left == nullptr) return Null::getInstance();
	if (!left->of()) return Boolean::getFalse();

	Object_* objRight = getRight()->eval();
	Boolean* right = objRight->asBoolean();
	if (right == nullptr) return Null::getInstance();
	if (!right->of()) return Boolean::getFalse();
	return Boolean::getTrue();
}
//---private method
