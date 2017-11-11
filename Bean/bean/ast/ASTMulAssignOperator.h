#pragma once
#ifndef BEAN_AST_ASTMULASSIGNOPERATOR_H
#define BEAN_AST_ASTMULASSIGNOPERATOR_H
#include "ASTAssignOperator.h"
/**
 * *= ‰‰ŽZŽq.
 */
class ASTMulAssignOperator : public ASTAssignOperator {
public:
	ASTMulAssignOperator();
	~ASTMulAssignOperator();
	Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTMulAssignOperator)
protected:
};
#endif // !BEAN_AST_ASTMULASSIGNOPERATOR_H


