#pragma once
#ifndef BEAN_AST_ASTEQUALOPERATOR_H
#define BEAN_AST_ASTEQUALOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * == ���Z�q.
 */
class ASTEqualOperator : public ASTBinaryOperator {
public:
	ASTEqualOperator();
	~ASTEqualOperator();

	// ASTOperator ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTEqualOperator)
protected:
};
#endif // !BEAN_AST_ASTEQUALOPERATOR_H


