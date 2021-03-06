#pragma once
#ifndef BEAN_AST_ASTANDANDOPERATOR_H
#define BEAN_AST_ASTANDANDOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * && 演算子.
 */
class ASTAndAndOperator : public ASTBinaryOperator {
public:
	ASTAndAndOperator();
	~ASTAndAndOperator();

	// ASTOperator を介して継承されました
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTAndAndOperator)
private:
	Object_* evalImpl();
};
#endif // !BEAN_AST_ASTANDANDOPERATOR_H


