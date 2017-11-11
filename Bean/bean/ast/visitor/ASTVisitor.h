#pragma once
#ifndef BEAN_AST_VISITOR_ASTVISITOR
#define BEAN_AST_VISITOR_ASTVISITOR
#include <memory>
class ASTNode;
class ASTName;
class ASTBody;
class ASTModifier;
class ASTParameter;
class ASTUnaryOperator;
class ASTBinaryOperator;
class ASTFactor;
class ASTIfStatement;
class ASTElseIfStatement;
class ASTElseStatement;
class ASTAliasStatement;
class ASTIncludeStatement;
class ASTClassDeclaration;
class ASTEnumDeclaration;
class ASTWhileStatement;
class ASTForStatement;
class ASTLambdaDeclaration;
class ASTVariableDeclaration;
class ASTMethodInvocation;
class ASTVariable;
class ASTNewStatement;
class ASTFieldDeclaration;
class ASTMethodDeclaration;
class ASTModifier;
class ASTTryStatement;
class ASTContinueStatement;
class ASTBreakStatement;
class ASTReturnStatement;
class ASTScheduledFactor;
class ASTDynFieldDeclaration;
class ASTDynMethodDeclaration;
class ASTFactor;
class ASTThrow;
/**
 * 抽象構文木の全ての要素を訪問するビジター.
 */
class ASTVisitor {
public:
	ASTVisitor();
	virtual ~ASTVisitor() { /* empty */ };
	virtual void enter(std::shared_ptr<ASTNode> element) = 0;
	virtual void enter(std::shared_ptr<ASTContinueStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTBreakStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTReturnStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTThrow> element) = 0;
	virtual void enter(std::shared_ptr<ASTAliasStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTIncludeStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTDynFieldDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTDynMethodDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTClassDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTEnumDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTFieldDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTMethodDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTIfStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTWhileStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTForStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTLambdaDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTVariableDeclaration> element) = 0;
	virtual void enter(std::shared_ptr<ASTUnaryOperator> element) = 0;
	virtual void enter(std::shared_ptr<ASTBinaryOperator> element) = 0;
	virtual void enter(std::shared_ptr<ASTMethodInvocation> element) = 0;
	virtual void enter(std::shared_ptr<ASTFactor> element) = 0;
	virtual void enter(std::shared_ptr<ASTTryStatement> element) = 0;
	virtual void enter(std::shared_ptr<ASTScheduledFactor> element) = 0;

	virtual void exit(std::shared_ptr<ASTNode> element) = 0;
	virtual void exit(std::shared_ptr<ASTContinueStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTBreakStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTReturnStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTThrow> element) = 0;
	virtual void exit(std::shared_ptr<ASTAliasStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTIncludeStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTDynFieldDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTDynMethodDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTClassDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTEnumDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTFieldDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTMethodDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTIfStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTWhileStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTForStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTLambdaDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTVariableDeclaration> element) = 0;
	virtual void exit(std::shared_ptr<ASTUnaryOperator> element) = 0;
	virtual void exit(std::shared_ptr<ASTBinaryOperator> element) = 0;
	virtual void exit(std::shared_ptr<ASTMethodInvocation> element) = 0;
	virtual void exit(std::shared_ptr<ASTFactor> element) = 0;
	virtual void exit(std::shared_ptr<ASTTryStatement> element) = 0;
	virtual void exit(std::shared_ptr<ASTScheduledFactor> element) = 0;
};
#endif // !BEAN_AST_VISITOR_ASTVISITOR
