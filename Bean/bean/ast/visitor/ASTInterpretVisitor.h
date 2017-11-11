#pragma once
#ifndef BEAN_AST_VISITOR_ASTINTERPRETVISITOR_H
#define BEAN_AST_VISITOR_ASTINTERPRETVISITOR_H
#include <functional>
#include <stack>
#include "ASTNullVisitor.h"
#include "ExceptionHandle.h"
#include "../../env/ClassLoader.h"
#include "../../env/FunctionManager.h"
#include "../../ast/visitor/ASTMethodVisitor.h"
class Thread;
/**
 * ���ۍ\���؂����ߎ��s����N���X�ł�.
 */
class ASTInterpretVisitor : public ASTNullVisitor, public ExceptionHandle {
public:
	/**
	 * @param rootClassLoader
	 */
	ASTInterpretVisitor(ClassLoaderSPtr rootClassLoader);
	~ASTInterpretVisitor();
	/**
	 * �C���^�v���^�̏I���t���O�𗧂Ă܂�.
	 */
	void error();

	/**
	 * �C���^�v���^�̏I���t���O���N���A���܂�.
	 */
	void clear();

	// ASTVisitor ����Čp������܂���
	void enter(std::shared_ptr<ASTAliasStatement > element) override;
	void enter(std::shared_ptr<ASTIncludeStatement > element) override;
	void enter(std::shared_ptr<ASTIfStatement > element) override;
	void enter(std::shared_ptr<ASTDynFieldDeclaration > element) override;
	void enter(std::shared_ptr<ASTDynMethodDeclaration > element) override;
	void enter(std::shared_ptr<ASTWhileStatement > element) override;
	void enter(std::shared_ptr<ASTForStatement > element) override;
	void enter(std::shared_ptr<ASTVariableDeclaration > element) override;
	void enter(std::shared_ptr<ASTBinaryOperator > element) override;
	void enter(std::shared_ptr<ASTMethodInvocation > element) override;
	void enter(std::shared_ptr<ASTTryStatement> element) override;
	void enter(std::shared_ptr<ASTScheduledFactor> element) override;
	void onException(Thread* t, Object_* e) override;
	void onCatch() override;
private:
	ClassLoaderSPtr getCLL();

	void init(ASTMethodVisitor* mv);
	ASTMethodVisitor* newVisitor();
	bool exit();

	ClassLoaderSPtr rootClassLoader;
	bool exifOfintrrupt;
	bool catched;
};
#endif // !BEAN_AST_VISITOR_ASTINTERPRETVISITOR_H


