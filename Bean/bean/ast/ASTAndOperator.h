#pragma once
#ifndef BEAN_AST_ASTANDOPERATOR_H
#define BEAN_AST_ASTANDOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * & 演算子.
 */
class ASTAndOperator : public ASTBinaryOperator {
public:
	ASTAndOperator();
	~ASTAndOperator();

	// ASTOperator を介して継承されました
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTAndOperator)
};
#endif // !BEAN_AST_ASTANDOPERATOR_H


