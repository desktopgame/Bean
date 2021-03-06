#pragma once
#ifndef BEAN_AST_ASTNEGATIVEOPERATOR_H
#define BEAN_AST_ASTNEGATIVEOPERATOR_H
#include "ASTUnaryOperator.h"
/**
 * 単項 - 演算子.
 */
class ASTNegativeOperator : public ASTUnaryOperator {
public:
	ASTNegativeOperator();
	~ASTNegativeOperator();

	// ASTFactor を介して継承されました
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTNegativeOperator)
private:
};

#endif // !BEAN_AST_ASTNEGATIVEOPERATOR_H
