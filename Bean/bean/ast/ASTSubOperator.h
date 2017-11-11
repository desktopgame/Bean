#pragma once
#ifndef BEAN_AST_ASTSUBOPERATOR_H
#define BEAN_AST_ASTSUBOPERATOR_H
#include "ASTBinaryOperator.h"
#include "ASTFactor.h"
/**
 * - ‰‰ŽZŽq
 */
class ASTSubOperator : public ASTBinaryOperator {
public:
	ASTSubOperator();
	~ASTSubOperator();
	Object_* eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTSubOperator)
protected:
};
#endif // !BEAN_AST_ASTSUBOPERATOR_H
