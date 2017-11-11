#pragma once
#ifndef BEAN_ENV_CONSTRUCTOR_H
#define BEAN_ENV_CONSTRUCTOR_H
#include "Method.h"
#include "../ast/ASTConstructorChain.h"
using ClassSPtr = std::shared_ptr<Class>;
/**
 * �R���X�g���N�^.
 * �R���X�g���N�^�����s���邽�߂ɂ́A�t�B�[���h���i�[����̈���ɗp�ӂ��Ȃ���΂����Ȃ��̂ŁA
 * UserObject�𐶐����A�����invoker�Ƃ���proxy�ֈϏ����܂��B
 */
class Constructor_ : public Method {
public:
	Constructor_(ClassSPtr const classz, Modifier modifier, std::string name, Method* proxy);
	virtual ~Constructor_();

	/**
	 * �A�����ݒ肵�܂�.
	 * @param chain
	 */
	virtual void setChain(std::shared_ptr<ASTConstructorChain> chain);

	/**
	 * �A�����Ԃ��܂�.
	 * @return
	 */
	virtual std::shared_ptr<ASTConstructorChain> getChain() const;

	//������proxy�ւ��Ϗ����܂��B
	virtual void addParameter(Parameter* param) override;
	virtual Parameter* const getParameterAt(int index) const override;
	virtual void removeParameterAt(int index) override;
	virtual int getParameterCount() const override;
	/**
	 * �߂�l�͈Ϗ����\�b�h�̖߂�l�ł͂Ȃ�(����͏��null�Ȃ̂�)
	 * �������ꂽUserObject�����b�v����Object_�ł�.
	 * @param invoker ��������܂��B
	 * @param args
	 */
	virtual Object_ * const execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) override;

	/**
	 * �R���X�g���N�^�̎�����Ԃ��܂�.
	 * @return
	 */
	virtual Method* const getProxy() const;
protected:

	bool deleteProxy;
private:
	Method* proxy;
	std::shared_ptr<ASTConstructorChain> chain;
};
#endif // !BEAN_ENV_CONSTRUCTOR_H


