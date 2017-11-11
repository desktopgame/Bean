#pragma once
#ifndef BEAN_ENV_LAMBDADELEGATE_H
#define BEAN_ENV_LAMBDADELEGATE_H
#include <string>
#include <unordered_map>
#include "Delegate.h"
class ASTLambdaDeclaration;
/**
 * �����_���𗘗p�����f���Q�[�g�̎����ł�.
 */
class LambdaDelegate : public Delegate {
public:
	/**
	 * @param lambdaDecl
	 */
	LambdaDelegate(ASTLambdaDeclaration* lambdaDecl);
	~LambdaDelegate();
	/**
	 * �����_�̊O���̕ϐ���ǉ����܂�.
	 * �����Œǉ����ꂽ�ϐ���GC�̑ΏۂɂȂ炸�A
	 * �����_�̓�������g�p���邱�Ƃ��o���܂��B
	 * @param name
	 */
	void addOutsideReference(std::string name);
	// Delegate ����Čp������܂���
	virtual Object_* call(ThreadSPtr t, ClassLoaderSPtr cll, std::vector<Object_*> args) override;
	virtual Object_ * call(ClassLoaderSPtr cll, std::vector<Object_*> args) override;
	virtual int requestArgumentCount() override;
	std::vector<Object_*> getVirtualField(ClassLoaderSPtr cll) override;
private:
//	std::unordered_map<std::string, Object_*> outerObject_s;
	std::vector<std::string> outerObject_s;
	ASTLambdaDeclaration* lambdaDecl;
};
#endif // !BEAN_ENV_LAMBDADELEGATE_H


