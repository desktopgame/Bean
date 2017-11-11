#pragma once
#ifndef BEAN_AST_ASTSMALLESTOPERATOR_H
#define BEAN_AST_ASTSMALLESTOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * < ‰‰ŽZŽq.
 */
class ASTSmallestOperator : public ASTBinaryOperator {
public:
	ASTSmallestOperator();
	~ASTSmallestOperator();

	// ASTOperator ‚ð‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTSmallestOperator)
protected:
};
#endif // !BEAN_AST_ASTSMALLESTOPERATOR_H


