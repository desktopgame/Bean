#pragma once
#ifndef BEAN_AST_ASTSUBASSIGNOPERATOR_H
#define BEAN_AST_ASTSUBASSIGNOPERATOR_H
#include "ASTAssignOperator.h"
/**
 * -= ‰‰ŽZŽq.
 */
class ASTSubAssignOperator : public ASTAssignOperator {
public:
	ASTSubAssignOperator();
	~ASTSubAssignOperator();
	Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTSubAssignOperator)
protected:
};
#endif // !BEAN_AST_ASTSUBASSIGNOPERATOR_H


