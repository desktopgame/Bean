#pragma once
#ifndef BEAN_AST_ASTADDASSIGNOPERATOR_H
#define BEAN_AST_ASTADDASSIGNOPERATOR_H
#include "ASTAssignOperator.h"

/**
 * += ‰‰ŽZŽq.
 */
class ASTAddAssignOperator : public ASTAssignOperator {
public:
	ASTAddAssignOperator();
	~ASTAddAssignOperator();

	virtual Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTAddAssignOperator)
protected:
};
#endif // !BEAN_AST_ASTADDASSIGNOPERATOR_H


