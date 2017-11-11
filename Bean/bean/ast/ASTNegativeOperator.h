#pragma once
#ifndef BEAN_AST_ASTNEGATIVEOPERATOR_H
#define BEAN_AST_ASTNEGATIVEOPERATOR_H
#include "ASTUnaryOperator.h"
/**
 * íPçÄ - ââéZéq.
 */
class ASTNegativeOperator : public ASTUnaryOperator {
public:
	ASTNegativeOperator();
	~ASTNegativeOperator();

	// ASTFactor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTNegativeOperator)
private:
};

#endif // !BEAN_AST_ASTNEGATIVEOPERATOR_H
