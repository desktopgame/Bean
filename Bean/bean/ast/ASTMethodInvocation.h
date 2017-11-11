#pragma once
#ifndef BEAN_AST_ASTMETHODINVOCATION_H
#define BEAN_AST_ASTMETHODINVOCATION_H
#include <functional>
#include <string>
#include "ASTFactor.h"
#include "../env/MessageQueue.h"
#include "../threads/Thread.h"
class ASTNode;
class ASTName;
class ClassLoader;
class ASTMethodInvocationByMessage;
class ASTMethodInvocationBySelf;
/**
 * ���\�b�h�Ăяo��.
 * ���\�b�h�`�F�[���͘A�����X�g�ɂ���ĕ\����܂��B
 * �������A�r�W�^�[�̓g�b�v�̃��\�b�h�����K��o���܂���B
 */
class ASTMethodInvocation : public ASTFactor {
public:
	ASTMethodInvocation();
	/**
	 * �Ăяo����郁�\�b�h�̖��O��ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * �Ăяo����郁�\�b�h�̖��O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * �Ăяo����郁�\�b�h�ɓn����������ǉ����܂�.
	 * @param factor
	 */
	void addArgument(std::shared_ptr<ASTFactor> factor);

	/**
	 * �w��ʒu�̈�����Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTFactor> getArgumentAt(int index) const;

	/**
	 * �Ăяo����郁�\�b�h�ɓn���������̐���Ԃ��܂�.
	 * @return
	 */
	int getArgumentCount() const;

	/**
	 * ���̃��\�b�h���A�����Ă���Ȃ�A����̃I�u�W�F�N�g��ݒ肵�܂�.
	 * @param invocation
	 */
	void setInvocation(std::shared_ptr<ASTMethodInvocation> invocation);

	/**
	 * ���̃��\�b�h���A�����Ă���Ȃ�A����̃I�u�W�F�N�g��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTMethodInvocation> getInvocation() const;

	/**
	 * NoClassError���w��̃N���X���[�_�[�ŃX���[���܂�.
	 * @param cll
	 * @param className
	 */
	static void throwNoClassError(ClassLoaderSPtr cll, std::string className);

	/**
	 * NoMethodError���w��̃N���X���[�_�[�ŃX���[���܂�.
	 * @param cll
	 * @param className
	 * @param methodName
	 * @param argCount
	 */
	static void throwNoMethodError(ClassLoaderSPtr cll, std::string className, std::string methodName, int argCount);

	/**
	 * ���̃C���X�^���X��ASTMethodInvocationByMessage�֕ϊ����܂�.
	 * �ϊ��o���Ȃ������ꍇ��nullptr��Ԃ��܂��B
	 * @return
	 */
	virtual std::shared_ptr<ASTMethodInvocationByMessage> asByMessage();

	/**
	 * ���̃C���X�^���X��ASTMethodInvocationBySelf�֕ϊ����܂�.
	 * �ϊ��o���Ȃ������ꍇ��nullptr��Ԃ��܂��B
	 * @return
	 */
	virtual std::shared_ptr<ASTMethodInvocationBySelf> asBySelf();

	virtual std::string format() const override;
	virtual void accept(ASTVisitor* visitor) override;

protected:

	/**
	 * �������v�Z���ĕԂ��܂�.
	 * @param f
	 * @return
	 */
	std::vector<Object_*> getEvalArguments(Function* f);

	/**
	 * �������v�Z���ĕԂ��܂�.
	 * @param m
	 * @return
	 */
	std::vector<Object_*> getEvalArguments(Method* m);

	std::vector<std::shared_ptr<ASTFactor>> arguments;
	virtual ~ASTMethodInvocation();
private:
	std::vector <Object_*> getEvalArgumentImpl(std::function<void(int)> f);
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTMethodInvocation> invocation;

};
#endif // !BEAN_AST_ASTMETHODINVOCATION_H
