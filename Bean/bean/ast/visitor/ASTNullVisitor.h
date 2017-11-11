#pragma once
#ifndef BEAN_AST_VISITOR_ASTNULLVISITOR_H
#define BEAN_AST_VISITOR_ASTNULLVISITOR_H
#include "ASTVisitor.h"
/**
 * ASTVisitorの空っぽの実装です.
 * サブクラスでは必要に応じてオーバーライド出来ます。
 */
class ASTNullVisitor : public ASTVisitor {
public:
	ASTNullVisitor();
	virtual ~ASTNullVisitor();

	virtual void enter(std::shared_ptr<ASTNode> element) override;
	virtual void enter(std::shared_ptr<ASTContinueStatement> element) override;
	virtual void enter(std::shared_ptr<ASTBreakStatement> element) override;
	virtual void enter(std::shared_ptr<ASTReturnStatement> element) override;
	virtual void enter(std::shared_ptr<ASTThrow> element) override;
	virtual void enter(std::shared_ptr<ASTAliasStatement> element) override;
	virtual void enter(std::shared_ptr<ASTIncludeStatement> element) override;
	virtual void enter(std::shared_ptr<ASTDynFieldDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTDynMethodDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTClassDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTEnumDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTFieldDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTMethodDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTIfStatement> element) override;
	virtual void enter(std::shared_ptr<ASTWhileStatement> element) override;
	virtual void enter(std::shared_ptr<ASTForStatement> element) override;
	virtual void enter(std::shared_ptr<ASTLambdaDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTVariableDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTUnaryOperator> element) override;
	virtual void enter(std::shared_ptr<ASTBinaryOperator> element) override;
	virtual void enter(std::shared_ptr<ASTMethodInvocation> element) override;
	virtual void enter(std::shared_ptr<ASTFactor> element) override;
	virtual void enter(std::shared_ptr<ASTTryStatement> element) override;
	virtual void enter(std::shared_ptr<ASTScheduledFactor> element) override;

	virtual void exit(std::shared_ptr<ASTNode> element) override;
	virtual void exit(std::shared_ptr<ASTContinueStatement> element) override;
	virtual void exit(std::shared_ptr<ASTBreakStatement> element) override;
	virtual void exit(std::shared_ptr<ASTReturnStatement> element) override;
	virtual void exit(std::shared_ptr<ASTThrow> element) override;
	virtual void exit(std::shared_ptr<ASTAliasStatement> element) override;
	virtual void exit(std::shared_ptr<ASTIncludeStatement> element) override;
	virtual void exit(std::shared_ptr<ASTDynFieldDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTDynMethodDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTClassDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTEnumDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTFieldDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTMethodDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTIfStatement> element) override;
	virtual void exit(std::shared_ptr<ASTWhileStatement> element) override;
	virtual void exit(std::shared_ptr<ASTForStatement> element) override;
	virtual void exit(std::shared_ptr<ASTLambdaDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTVariableDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTUnaryOperator> element) override;
	virtual void exit(std::shared_ptr<ASTBinaryOperator> element) override;
	virtual void exit(std::shared_ptr<ASTMethodInvocation> element) override;
	virtual void exit(std::shared_ptr<ASTFactor> element) override;
	virtual void exit(std::shared_ptr<ASTTryStatement> element) override;
	virtual void exit(std::shared_ptr<ASTScheduledFactor> element) override;
protected:

};
#endif // !BEAN_AST_VISITOR_ASTNULLVISITOR_H


