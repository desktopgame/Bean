#pragma once
#ifndef AST_ASTOROPERATOR_H
#define AST_ASTOROPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * | ‰‰ŽZŽq.
 */
class ASTOrOperator : public ASTBinaryOperator {
public:
	ASTOrOperator();
	~ASTOrOperator();
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTOrOperator)
protected:
};
#endif // !AST_ASTOROPERATOR_H


