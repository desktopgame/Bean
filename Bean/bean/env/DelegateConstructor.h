#pragma once
#ifndef BEAN_ENV_DELEGATECONSTRUCTOR_H
#define BEAN_ENV_DELEGATECONSTRUCTOR_H
#include "Constructor_.h"
/**
 * �R���X�g���N�^�������`����Ȃ��N���X�ŁA
 * �����I�ɍ쐬�����Ϗ����邾���̃R���X�g���N�^�ł��B
 */
class DelegateConstructor : public Constructor_ {
public:
	DelegateConstructor(ClassSPtr cls, Constructor_* cons);
	~DelegateConstructor();
	virtual void setChain(std::shared_ptr<ASTConstructorChain> chain);
	virtual std::shared_ptr<ASTConstructorChain> getChain() const;
	virtual void addParameter(Parameter* param) override;
	virtual void removeParameterAt(int index) override;
	virtual Object_ * const execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) override;
	virtual Method* const getProxy() const;
private:
	Constructor_* cons;
	std::shared_ptr<ASTConstructorChain> chain;
	ClassWPtr cls;
};
#endif // !BEAN_ENV_DELEGATECONSTRUCTOR_H
