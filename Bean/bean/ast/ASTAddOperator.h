#pragma once
#ifndef BEAN_AST_ASTADDOPERATOR_H
#define BEAN_AST_ASTADDOPERATOR_H
#include "ASTBinaryOperator.h"
#include "ASTFactor.h"

/**
 * + ‰‰ŽZŽq.
 */
class ASTAddOperator : public ASTBinaryOperator {
public:
	ASTAddOperator();
	~ASTAddOperator();
	Object_* eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTAddOperator)
};
#endif // !BEAN_AST_ASTADDOPERATOR_H
