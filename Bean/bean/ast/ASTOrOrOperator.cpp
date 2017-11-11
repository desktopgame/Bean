#include "ASTOrOrOperator.h"
#include "../env/Boolean.h"
#include "../env/Null.h"
#include "../env/Object_.h"

//public method---
ASTOrOrOperator::ASTOrOrOperator() {
}

ASTOrOrOperator::~ASTOrOrOperator() {
}

Object_ * ASTOrOrOperator::eval() {
	buffer_begin();
	Object_* retVal = evalImpl();
	buffer_end();
	return retVal;
}

std::string ASTOrOrOperator::format() const {
	return "||";
}
IMPL_MAKE_SHARED_0_CPP(ASTOrOrOperator)
//---public method


//protected method---
Object_ * ASTOrOrOperator::evalImpl() {
	//‚Ç‚¿‚ç‚©‚ªtrue‚È‚ç‚à‚¤•Ð•û‚Í•]‰¿‚µ‚È‚¢
	Boolean* left = getLeft()->eval()->asBoolean();
	if (left == nullptr) return Null::getInstance();
	if (left->of()) return Boolean::getTrue();

	Boolean* right = getRight()->eval()->asBoolean();
	if (right == nullptr) return Null::getInstance();
	if (right->of()) return Boolean::getTrue();
	return Boolean::getFalse();
}
//---protected method
