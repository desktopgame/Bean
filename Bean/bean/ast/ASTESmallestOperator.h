#pragma once
#ifndef BEAN_AST_ASTESMALLESTOPERATOR_H
#define BEAN_AST_ASTESMALLESTOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * <= ���Z�q.
 */
class ASTESmallestOperator : public ASTBinaryOperator {
public:
	ASTESmallestOperator();
	~ASTESmallestOperator();

	// ASTOperator ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTESmallestOperator)
protected:
};
#endif // !BEAN_AST_ASTESMALLESTOPERATOR_H

