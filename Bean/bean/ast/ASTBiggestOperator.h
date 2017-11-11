#pragma once
#ifndef BEAN_AST_ASTBIGGESTOPERATOR_H
#define BEAN_AST_ASTBIGGESTOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * < ���Z�q.
 */
class ASTBiggestOperator : public ASTBinaryOperator {
public:
	ASTBiggestOperator();
	~ASTBiggestOperator();

	// ASTOperator ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTBiggestOperator)
};
#endif // !BEAN_AST_ASTBIGGESTOPERATOR_H


