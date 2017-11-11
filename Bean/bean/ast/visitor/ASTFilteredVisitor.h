#pragma once
#ifndef BEAN_AST_VISITOR_ASTFILTEREDVISITOR_H
#define BEAN_AST_VISITOR_ASTFILTEREDVISITOR_H
#include "../ASTAliasStatement.h"
#include "../ASTBinaryOperator.h"
#include "../ASTBreakStatement.h"
#include "../ASTClassDeclaration.h"
#include "../ASTContinueStatement.h"
#include "../ASTDynFieldDeclaration.h"
#include "../ASTDynMethodDeclaration.h"
#include "../ASTElseIfStatement.h"
#include "../ASTElseStatement.h"
#include "../ASTEnumDeclaration.h"
#include "../ASTFactor.h"
#include "../ASTFieldDeclaration.h"
#include "../ASTForStatement.h"
#include "../ASTIfStatement.h"
#include "../ASTIncludeStatement.h"
#include "../ASTLambdaDeclaration.h"
#include "../ASTMethodDeclaration.h"
#include "../ASTMethodInvocation.h"
#include "../ASTMethodInvocationByMessage.h"
#include "../ASTMethodInvocationBySelf.h"
#include "../ASTModifier.h"
#include "../ASTName.h"
#include "../ASTNewStatement.h"
#include "../ASTReturnStatement.h"
#include "../ASTScheduledFactor.h"
#include "../ASTThrow.h"
#include "../ASTTryStatement.h"
#include "../ASTUnaryOperator.h"
#include "../ASTVariable.h"
#include "../ASTVariableDeclaration.h"
#include "../ASTWhileStatement.h"
#include "../InterpretExitException.h"
#include "../../env/Class.h"
#include "../../env/ClassFormatException.h"
#include "../../env/ClassLoader.h"
#include "../../env/CodeBlock.h"
#include "../../env/Function.h"
#include "../../env/IncludeManager.h"
#include "../../env/Method.h"
#include "../../env/Null.h"
#include "../../env/Object_.h"
#include "../../env/String.h"
#include "../../util/Memory.h"
#include "../../env/gc/Block.h"
#include "../../env/gc/Heap.h"
//
/**
 * フィルター付きビジターです.
 */
class ASTFilteredVisitor : public ASTVisitor {
public:
	ASTFilteredVisitor();
	virtual ~ASTFilteredVisitor();
	// ASTVisitor を介して継承されました
	virtual void enter(std::shared_ptr<ASTNode> element) override;
	virtual void enter(std::shared_ptr<ASTContinueStatement > element) override;
	virtual void enter(std::shared_ptr<ASTBreakStatement > element) override;
	virtual void enter(std::shared_ptr<ASTReturnStatement > element) override;
	virtual void enter(std::shared_ptr<ASTThrow > element) override;
	virtual void enter(std::shared_ptr<ASTAliasStatement > element) override;
	virtual void enter(std::shared_ptr<ASTClassDeclaration > element) override;
	virtual void enter(std::shared_ptr<ASTIncludeStatement > element) override;
	virtual void enter(std::shared_ptr<ASTDynFieldDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTDynMethodDeclaration > element) override;
	virtual void enter(std::shared_ptr<ASTEnumDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTFieldDeclaration > element) override;
	virtual void enter(std::shared_ptr<ASTMethodDeclaration > element) override;
	virtual void enter(std::shared_ptr<ASTIfStatement > element) override;
	virtual void enter(std::shared_ptr<ASTWhileStatement > element) override;
	virtual void enter(std::shared_ptr<ASTForStatement > element) override;
	virtual void enter(std::shared_ptr<ASTLambdaDeclaration> element) override;
	virtual void enter(std::shared_ptr<ASTVariableDeclaration > element) override;
	virtual void enter(std::shared_ptr<ASTUnaryOperator > element) override;
	virtual void enter(std::shared_ptr<ASTBinaryOperator > element) override;
	virtual void enter(std::shared_ptr<ASTMethodInvocation > element) override;
	virtual void enter(std::shared_ptr<ASTFactor> element) override;
	virtual void enter(std::shared_ptr<ASTTryStatement> element) override;
	virtual void enter(std::shared_ptr<ASTScheduledFactor> element) override;

	virtual void exit(std::shared_ptr<ASTNode > element) override;
	virtual void exit(std::shared_ptr<ASTContinueStatement > element) override;
	virtual void exit(std::shared_ptr<ASTBreakStatement > element) override;
	virtual void exit(std::shared_ptr<ASTReturnStatement > element) override;
	virtual void exit(std::shared_ptr<ASTThrow > element) override;
	virtual void exit(std::shared_ptr<ASTAliasStatement > element) override;
	virtual void exit(std::shared_ptr<ASTIncludeStatement > element) override;
	virtual void exit(std::shared_ptr<ASTDynFieldDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTDynMethodDeclaration > element) override;
	virtual void exit(std::shared_ptr<ASTClassDeclaration > element) override;
	virtual void exit(std::shared_ptr<ASTEnumDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTFieldDeclaration > element) override;
	virtual void exit(std::shared_ptr<ASTMethodDeclaration > element) override;
	virtual void exit(std::shared_ptr<ASTIfStatement > element) override;
	virtual void exit(std::shared_ptr<ASTWhileStatement > element) override;
	virtual void exit(std::shared_ptr<ASTForStatement > element) override;
	virtual void exit(std::shared_ptr<ASTLambdaDeclaration> element) override;
	virtual void exit(std::shared_ptr<ASTVariableDeclaration > element) override;
	virtual void exit(std::shared_ptr<ASTUnaryOperator > element) override;
	virtual void exit(std::shared_ptr<ASTBinaryOperator > element) override;
	virtual void exit(std::shared_ptr<ASTMethodInvocation > element) override;
	virtual void exit(std::shared_ptr<ASTFactor> element) override;
	virtual void exit(std::shared_ptr<ASTTryStatement> element) override;
	virtual void exit(std::shared_ptr<ASTScheduledFactor> element) override;
protected:
	/**
	 * 未知の要素について処理します.
	 * このメソッドが適切に呼び出されるために、
	 * サブクラスでは enterXXX, exitXXX を必要なもののみオーバーライドしてください。
	 * このクラスの enterXXX, exitXXX は常に enterUnknown, exitUnknown を呼び出すようになっています。
	 */
	virtual void enterUnknown(std::shared_ptr<ASTNode> element);

	/**
	 * 未知の要素について処理します.
	 */
	virtual void exitUnknown(std::shared_ptr<ASTNode> element);
private:
	void callEnterUnknown(std::shared_ptr<ASTNode> element);
	void callExitUnknown(std::shared_ptr<ASTNode> element);
};
#endif // !BEAN_AST_VISITOR_ASTFILTEREDVISITOR_H
