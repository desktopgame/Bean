#pragma once
#ifndef BEAN_AST_ASTMODOPERATOR_H
#define BEAN_AST_ASTMODOPERATOR_H
#include "ASTBinaryOperator.h"
#include "ASTFactor.h"
/**
 * %‰‰ŽZŽq.
 */
class ASTModOperator : public ASTBinaryOperator {
public:
	ASTModOperator();
	~ASTModOperator();
	Object_* eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTModOperator)
protected:
};
#endif // !BEAN_AST_ASTMODOPERATOR_H


