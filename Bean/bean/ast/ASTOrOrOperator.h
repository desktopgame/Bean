#pragma once
#ifndef BEAN_AST_ASTOROROPERATOR_H
#define BEAN_AST_ASTOROROPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * || ââéZéq.
 */
class ASTOrOrOperator : public ASTBinaryOperator {
public:
	ASTOrOrOperator();
	~ASTOrOrOperator();

	// ASTOperator ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTOrOrOperator)
protected:
	Object_* evalImpl();
};
#endif // !BEAN_AST_ASTOROROPERATOR_H


