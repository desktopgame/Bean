#pragma once
#ifndef BEAN_AST_ASTNEGATIVEOPERATOR_H
#define BEAN_AST_ASTNEGATIVEOPERATOR_H
#include "ASTUnaryOperator.h"
/**
 * �P�� - ���Z�q.
 */
class ASTNegativeOperator : public ASTUnaryOperator {
public:
	ASTNegativeOperator();
	~ASTNegativeOperator();

	// ASTFactor ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTNegativeOperator)
private:
};

#endif // !BEAN_AST_ASTNEGATIVEOPERATOR_H
