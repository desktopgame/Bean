#pragma once
#ifndef BEAN_AST_ASTMETHODINVOCATIONBYMESSAGE_H
#define BEAN_AST_ASTMETHODINVOCATIONBYMESSAGE_H
#include "ASTFactor.h"
#include "ASTMethodInvocation.h"
/**
 * ���߂ɂ�郁�\�b�h�Ăяo��.
 */
class ASTMethodInvocationByMessage : public ASTMethodInvocation {
public:
	ASTMethodInvocationByMessage();
	~ASTMethodInvocationByMessage();
	/**
	 * ���s����I�u�W�F�N�g��ݒ肵�܂�.
	 * @param invoker
	 */
	void setInvoker(std::shared_ptr<ASTFactor> invoker);

	/**
	 * ���s����I�u�W�F�N�g��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getInvoker() const;
	// ASTFactor ����Čp������܂���
	Object_ * eval() override;
	std::shared_ptr<ASTMethodInvocationByMessage> asByMessage() override;
	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTMethodInvocationByMessage)
private:
	Object_* evalImpl();
	std::shared_ptr<ASTFactor> invoker;

	//���������ꂽ���\�b�h��������
	//�ŏ��̈�x�����������Ă���ȍ~�̓L���b�V����Ԃ��܂�
	ClassSPtr findClassStatic(ClassLoaderSPtr cll, std::string name);
	Method* findMethodStatic(ClassSPtr classz, std::string name, int argc);
	Method* findMethodDynamic(Object_* obj, ClassSPtr classz, std::string name, int argc);

	bool cacheCompiled;
	ClassSPtr cacheClassStatic;
	Method* cacheMethodStatic;
	Method* cacheMethodDynamic;
};
#endif // !BEAN_AST_ASTMETHODINVOCATIONBYMESSAGE_H


