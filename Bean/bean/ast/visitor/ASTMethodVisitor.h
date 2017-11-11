#pragma once
#ifndef BEAN_ENV_METHODVISITOR_H
#define BEAN_ENV_METHODVISITOR_H
#include <string>
#include "ASTFilteredVisitor.h"
#include "ExceptionHandle.h"
class ClassLoader;
class Method;
class Object_;
class Thread;
class ASTInterpretVisitor;
#include "../../env/ClassLoaderSkeleton.h"
/**
 * ASTNodeで表される構文木を評価して処理を実行するビジターです.
 */
class ASTMethodVisitor : public ASTFilteredVisitor, public ExceptionHandle {
public:
	ASTMethodVisitor(ExceptionHandle* parent);
	ASTMethodVisitor(ThreadSPtr t);
	ASTMethodVisitor();
	~ASTMethodVisitor();

	void markException() {
		this->rethrow = true;
	}

	/**
	 * このビジターが読み込む対象の構文木を含むクラスローダーです.
	 * @return
	 */
	ClassLoaderSPtr getClassLoader();

	/**
	 * 既に例外でマークされているならtrueを返します.
	 * @return
	 */
	bool isThrown() const;

	/**
	 * このビジターが return によって終了したなら、
	 * 戻り値を返します。
	 * ただし、空のreturnの場合は null が返されます。
	 * @return
	 */
	Object_* getReturnValue() const;

	/**
	 * このビジターが例外でマークされているならそれを返します.
	 * @return
	 */
	Object_* getException() const;

	// ASTVisitor を介して継承されました
	void enter(std::shared_ptr<ASTNode > element) override;
	void enter(std::shared_ptr<ASTContinueStatement > element) override;
	void enter(std::shared_ptr<ASTBreakStatement > element) override;
	void enter(std::shared_ptr<ASTReturnStatement > element) override;
	void enter(std::shared_ptr<ASTThrow > element) override;
	void enter(std::shared_ptr<ASTDynFieldDeclaration > element) override;
	void enter(std::shared_ptr<ASTDynMethodDeclaration > element) override;
	void enter(std::shared_ptr<ASTIfStatement > element) override;
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
	ASTMethodVisitor* newVisitor();

	/**
	* このインスタンスを指定の例外でマークします.
	* 例外でマークされると、以降の処理はスキップされます。
	* @param exception
	*/
	void longJump(Object_* exception);
	void init(ThreadSPtr t, ExceptionHandle* parent);
	
	bool isShutdown();
	bool next;
	bool async;
	bool aexit;
	bool thrown;
	bool hasException;
	bool hasRetVal;
	bool rethrow;
	ExceptionHandle* parent;
	ClassLoaderSPtr classLoader;
	Object_* exception;
	Object_* returnValue;
};
#endif // !BEAN_ENV_METHODVISITOR_H


