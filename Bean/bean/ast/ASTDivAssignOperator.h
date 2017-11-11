#pragma once
#ifndef BEAN_AST_ASTDIVASSIGNOPERATOR_H
#define BEAN_AST_ASTDIVASSIGNOPERATOR_H
#include "ASTAssignOperator.h"
/**
 * /= ���Z�q.
 */
class ASTDivAssignOperator : public ASTAssignOperator {
public:
	ASTDivAssignOperator();
	~ASTDivAssignOperator();
	Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTDivAssignOperator)
};
#endif // !BEAN_AST_ASTDIVASSIGNOPERATOR_H


