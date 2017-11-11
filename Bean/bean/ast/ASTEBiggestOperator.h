#pragma once
#ifndef BEAN_AST_ASTEBIGGESTOPERATOR_H
#define BEAN_AST_ASTEBIGGESTOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * >= ���Z�q.
 */
class ASTEBiggestOperator : public ASTBinaryOperator {
public:
	ASTEBiggestOperator();
	~ASTEBiggestOperator();

	// ASTOperator ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTEBiggestOperator)
};
#endif // !BEAN_AST_ASTEBIGGESTOPERATOR_H


