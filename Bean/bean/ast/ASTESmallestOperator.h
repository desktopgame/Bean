#pragma once
#ifndef BEAN_AST_ASTESMALLESTOPERATOR_H
#define BEAN_AST_ASTESMALLESTOPERATOR_H
#include "ASTBinaryOperator.h"
/**
 * <= ‰‰ŽZŽq.
 */
class ASTESmallestOperator : public ASTBinaryOperator {
public:
	ASTESmallestOperator();
	~ASTESmallestOperator();

	// ASTOperator ‚ð‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTESmallestOperator)
protected:
};
#endif // !BEAN_AST_ASTESMALLESTOPERATOR_H

