#pragma once
#ifndef BEAN_AST_ASTNOTEQUALSOPERATOR_H
#define BEAN_AST_ASTNOTEQUALSOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * !=.
 */
class ASTNotEqualsOperator : public ASTBinaryOperator {
public:
	ASTNotEqualsOperator();
	~ASTNotEqualsOperator();
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTNotEqualsOperator)
protected:
};
#endif // !BEAN_AST_ASTNOTEQUALSOPERATOR_H


