#pragma once
#ifndef BEAN_AST_ASTPOSITIVEOPERATOR_H
#define BEAN_AST_ASTPOSITIVEOPERATOR_H
#include "ASTUnaryOperator.h"
//NOTE:�g�p����Ă��܂���B
/**
 * �P�� + ���Z�q.
 */
class ASTPositiveOperator : public ASTUnaryOperator {
public:
	ASTPositiveOperator();
	~ASTPositiveOperator();
	// ASTFactor ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTPositiveOperator)
private:
};
#endif // !BEAN_AST_ASTPOSITIVEOPERATOR_H
