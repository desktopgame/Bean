#pragma once
#ifndef BEAN_AST_ASTPOSITIVEOPERATOR_H
#define BEAN_AST_ASTPOSITIVEOPERATOR_H
#include "ASTUnaryOperator.h"
//NOTE:使用されていません。
/**
 * 単項 + 演算子.
 */
class ASTPositiveOperator : public ASTUnaryOperator {
public:
	ASTPositiveOperator();
	~ASTPositiveOperator();
	// ASTFactor を介して継承されました
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTPositiveOperator)
private:
};
#endif // !BEAN_AST_ASTPOSITIVEOPERATOR_H
