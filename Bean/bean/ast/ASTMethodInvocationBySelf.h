#pragma once
#ifndef BEAN_AST_ASTMETHODINVOCATIONBYSELF_H
#define BEAN_AST_ASTMETHODINVOCATIONBYSELF_H
#include "ASTMethodInvocation.h"
/**
 * ���g�ɒ�`����Ă��郁�\�b�h�̌Ăяo��.
 */
class ASTMethodInvocationBySelf : public ASTMethodInvocation  {
public:
	ASTMethodInvocationBySelf();
	~ASTMethodInvocationBySelf();
	Object_ * eval() override;
	std::shared_ptr<ASTMethodInvocationBySelf> asBySelf() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTMethodInvocationBySelf)
protected:
private:
	Object_* evalImpl();

	//���������ꂽ���\�b�h��������
	//�ŏ��̈�x�����������Ă���ȍ~�̓L���b�V����Ԃ��܂�
	Function* findTopLevelFunction(FunctionManager* fm, std::string name, int argc);
	Method* findSelfMethod(ClassSPtr classz, std::string name, int argc);

	bool cacheCompiled;
	Function* cacheTopLevelFunction;
	Method* cacheSelfMethod;
};
#endif // BEAN_AST_ASTMETHODINVOCATIONBYSELF_H


