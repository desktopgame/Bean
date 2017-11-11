#pragma once
#ifndef BEAN_AST_ASTANDOPERATOR_H
#define BEAN_AST_ASTANDOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * & ���Z�q.
 */
class ASTAndOperator : public ASTBinaryOperator {
public:
	ASTAndOperator();
	~ASTAndOperator();

	// ASTOperator ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTAndOperator)
};
#endif // !BEAN_AST_ASTANDOPERATOR_H


