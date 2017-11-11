#pragma once
#ifndef BEAN_AST_ASTMODASSIGNOPERATOR_H
#define BEAN_AST_ASTMODASSIGNOPERATOR_H
#include "ASTAssignOperator.h"
/**
 * %= ‰‰ŽZŽq.
 */
class ASTModAssignOperator : public ASTAssignOperator {
public:
	ASTModAssignOperator();
	~ASTModAssignOperator();
	Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTModAssignOperator)
protected:
};
#endif // !BEAN_AST_ASTMODASSIGNOPERATOR_H


