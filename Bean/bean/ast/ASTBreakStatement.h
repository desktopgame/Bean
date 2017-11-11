#pragma once
#ifndef BEAN_AST_ASTBREAKSTATEMENT_H
#define BEAN_AST_ASTBREAKSTATEMENT_H
#include "ASTNode.h"
/**
 * break•¶.
 */
class ASTBreakStatement : public ASTNode {
public:
	ASTBreakStatement();
	~ASTBreakStatement();
	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTBreakStatement)
};
#endif // !BEAN_AST_ASTBREAKSTATEMENT_H


