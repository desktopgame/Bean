#pragma once
#ifndef BEAN_AST_ASTEQUALOPERATOR_H
#define BEAN_AST_ASTEQUALOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * == 演算子.
 */
class ASTEqualOperator : public ASTBinaryOperator {
public:
	ASTEqualOperator();
	~ASTEqualOperator();

	// ASTOperator を介して継承されました
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTEqualOperator)
protected:
};
#endif // !BEAN_AST_ASTEQUALOPERATOR_H


