#pragma once
#ifndef BEAN_AST_ASTCONTINUESTATEMENT_H
#define BEAN_AST_ASTCONTINUESTATEMENT_H
#include "ASTNode.h"
/**
 * continue•¶.
 */
class ASTContinueStatement : public ASTNode {
public:
	ASTContinueStatement();
	~ASTContinueStatement();
	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTContinueStatement)
};
#endif // !BEAN_AST_ASTCONTINUESTATEMENT_H


