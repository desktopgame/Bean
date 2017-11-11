#pragma once
#ifndef BEAN_AST_ASTMULOPERATOR_H
#define BEAN_AST_ASTMULOPERATOR_H
#include "ASTBinaryOperator.h"
#include "ASTFactor.h"
/**
 * * ‰‰ŽZŽq.
 */
class ASTMulOperator : public ASTBinaryOperator {
public:
	ASTMulOperator();
	~ASTMulOperator();
	Object_* eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTMulOperator)
protected:
};
#endif // !BEAN_AST_ASTMULOPERATOR_H
