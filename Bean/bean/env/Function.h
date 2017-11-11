#pragma once
#ifndef BEAN_ENV_FUNCTION_H
#define BEAN_ENV_FUNCTION_H
#include <vector>
class Object_;
//class ASTMethodDeclaration;
#include "../ast/ASTMethodDeclaration.h"
/**
 * �g�b�v���x���ɒ�`�����֐��ł�.
 */
class Function {
public:
	Function(std::shared_ptr<ASTMethodDeclaration> methodDecl);
	~Function();

	/**
	 * ���̊֐������s���܂�.
	 * @param args
	 */
	Object_* const call(std::vector<Object_*> args);

	/**
	 * ���O��Ԃ��܂�.
	 * @return
	 */
	std::string getName();

	/**
	 * �����̐���Ԃ��܂�.
	 * @return
	 */
	int getArgumentCount();
private:
	std::shared_ptr<ASTMethodDeclaration> methodDecl;
};
#endif // !BEAN_ENV_FUNCTION_H


