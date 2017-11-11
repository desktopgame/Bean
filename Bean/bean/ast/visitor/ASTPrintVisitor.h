#pragma once
#ifndef BEAN_AST_VISITOR_ASTPRINTVISITOR
#define BEAN_AST_VISITOR_ASTPRINTVISITOR
#include <iostream>
#include <string>
//#include <memory>
#include "ASTVisitor.h"
//#include "ASTNullVisitor.h"
/*
*/
/**
 * íäè€ç\ï∂ñÿÇÉ_ÉìÉvÇ∑ÇÈÇΩÇﬂÇÃé¿ëïÇ≈Ç∑.
 */
class ASTPrintVisitor : public ASTVisitor {
public:
	ASTPrintVisitor();
	~ASTPrintVisitor();

	// ASTVisitor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	void enter(std::shared_ptr<ASTNode> element) override;
	void enter(std::shared_ptr<ASTContinueStatement> element) override;
	void enter(std::shared_ptr<ASTBreakStatement> element) override;
	void enter(std::shared_ptr<ASTReturnStatement> element) override;
	void enter(std::shared_ptr<ASTThrow> element) override;
	void enter(std::shared_ptr<ASTDynFieldDeclaration> element) override;
	void enter(std::shared_ptr<ASTDynMethodDeclaration> element) override;
	void enter(std::shared_ptr<ASTAliasStatement> element) override;
	void enter(std::shared_ptr<ASTIncludeStatement> element) override;
	void enter(std::shared_ptr<ASTClassDeclaration> element) override;
	void enter(std::shared_ptr<ASTEnumDeclaration> element) override;
	void enter(std::shared_ptr<ASTFieldDeclaration> element) override;
	void enter(std::shared_ptr<ASTMethodDeclaration> element) override;
	void enter(std::shared_ptr<ASTIfStatement> element) override;
	void enter(std::shared_ptr<ASTWhileStatement> element) override;
	void enter(std::shared_ptr<ASTForStatement> element) override;
	void enter(std::shared_ptr<ASTLambdaDeclaration> element) override;
	void enter(std::shared_ptr<ASTVariableDeclaration> element) override;
	void enter(std::shared_ptr<ASTUnaryOperator> element) override;
	void enter(std::shared_ptr<ASTBinaryOperator> element) override;
	void enter(std::shared_ptr<ASTMethodInvocation> element) override;
	void enter(std::shared_ptr<ASTFactor> element) override;
	void enter(std::shared_ptr<ASTTryStatement> element) override;
	void enter(std::shared_ptr<ASTScheduledFactor> element) override;

	void exit(std::shared_ptr<ASTNode> element) override;
	void exit(std::shared_ptr<ASTContinueStatement> element) override;
	void exit(std::shared_ptr<ASTBreakStatement> element) override;
	void exit(std::shared_ptr<ASTReturnStatement> element) override;
	void exit(std::shared_ptr<ASTThrow> element) override;
	void exit(std::shared_ptr<ASTDynFieldDeclaration> element) override;
	void exit(std::shared_ptr<ASTDynMethodDeclaration> element) override;
	void exit(std::shared_ptr<ASTAliasStatement> element) override;
	void exit(std::shared_ptr<ASTIncludeStatement> element) override;
	void exit(std::shared_ptr<ASTClassDeclaration> element) override;
	void exit(std::shared_ptr<ASTEnumDeclaration> element) override;
	void exit(std::shared_ptr<ASTFieldDeclaration> element) override;
	void exit(std::shared_ptr<ASTMethodDeclaration> element) override;
	void exit(std::shared_ptr<ASTIfStatement> element) override;
	void exit(std::shared_ptr<ASTWhileStatement> element) override;
	void exit(std::shared_ptr<ASTForStatement> element) override;
	void exit(std::shared_ptr<ASTLambdaDeclaration> element) override;
	void exit(std::shared_ptr<ASTVariableDeclaration> element) override;
	void exit(std::shared_ptr<ASTUnaryOperator> element) override;
	void exit(std::shared_ptr<ASTBinaryOperator> element) override;
	void exit(std::shared_ptr<ASTMethodInvocation> element) override;
	void exit(std::shared_ptr<ASTFactor> element) override;
	void exit(std::shared_ptr<ASTTryStatement> element) override;
	void exit(std::shared_ptr<ASTScheduledFactor> element) override;
private:
	int depth;
	void print(std::shared_ptr<ASTNode> parent);
	std::string makeIndent();

};
#endif // !BEAN_AST_VISITOR_ASTPRINTVISITOR
