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
 * ASTNode�ŕ\�����\���؂�]�����ď��������s����r�W�^�[�ł�.
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
	 * ���̃r�W�^�[���ǂݍ��ޑΏۂ̍\���؂��܂ރN���X���[�_�[�ł�.
	 * @return
	 */
	ClassLoaderSPtr getClassLoader();

	/**
	 * ���ɗ�O�Ń}�[�N����Ă���Ȃ�true��Ԃ��܂�.
	 * @return
	 */
	bool isThrown() const;

	/**
	 * ���̃r�W�^�[�� return �ɂ���ďI�������Ȃ�A
	 * �߂�l��Ԃ��܂��B
	 * �������A���return�̏ꍇ�� null ���Ԃ���܂��B
	 * @return
	 */
	Object_* getReturnValue() const;

	/**
	 * ���̃r�W�^�[����O�Ń}�[�N����Ă���Ȃ炻���Ԃ��܂�.
	 * @return
	 */
	Object_* getException() const;

	// ASTVisitor ����Čp������܂���
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
	* ���̃C���X�^���X���w��̗�O�Ń}�[�N���܂�.
	* ��O�Ń}�[�N�����ƁA�ȍ~�̏����̓X�L�b�v����܂��B
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


