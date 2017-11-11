#pragma once
#ifndef BEAN_AST_ASTDIVOPERATOR_H
#define BEAN_AST_ASTDIVOPERATOR_H
#include "ASTBinaryOperator.h"
#include "ASTFactor.h"
/**
 * / ‰‰ŽZŽq.
 */
class ASTDivOperator : public ASTBinaryOperator {
public:
	ASTDivOperator();
	~ASTDivOperator();
	Object_* eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTDivOperator)
};
#endif // !BEAN_AST_ASTDIVOPERATOR_H


