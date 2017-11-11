#pragma once
#ifndef BEAN_AST_ASTOROROPERATOR_H
#define BEAN_AST_ASTOROROPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * || ���Z�q.
 */
class ASTOrOrOperator : public ASTBinaryOperator {
public:
	ASTOrOrOperator();
	~ASTOrOrOperator();

	// ASTOperator ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTOrOrOperator)
protected:
	Object_* evalImpl();
};
#endif // !BEAN_AST_ASTOROROPERATOR_H


