#pragma once
#ifndef BEAN_AST_ASTNOTOPERATOR_H
#define BEAN_AST_ASTNOTOPERATOR_H
#include "ASTFactor.h"
#include "ASTUnaryOperator.h"
/**
 * !any.
 */
class ASTNotOperator : public ASTUnaryOperator {
public:
	ASTNotOperator();
	~ASTNotOperator();
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTNotOperator)
protected:
private:
	//ASTFactor* condition;
};
#endif // !BEAN_AST_ASTNOTOPERATOR_H


