#pragma once
#ifndef BEAN_AST_ASTELSEIFSTATEMENT_H
#define BEAN_AST_ASTELSEIFSTATEMENT_H
#include "ASTIfCauseStatement.h"
class ASTNode;
class ASTBody;
class ASTFactor;
/**
 * elseif文.
 * 子要素として文を持つことが出来ます。
 */
class ASTElseIfStatement : public ASTIfCauseStatement {
public:
	ASTElseIfStatement();
	~ASTElseIfStatement();

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTElseIfStatement)
private:
};
#endif // !BEAN_AST_ASTELSEIFSTATEMENT_H
