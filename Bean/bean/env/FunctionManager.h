#pragma once
#ifndef BEAN_ENV_FUNCTIONMANAGER_H
#define BEAN_ENV_FUNCTIONMANAGER_H
#include <vector>
class Function;
/**
 * �g�b�v���x���̃N���X���[�_�[�Ŏg�p����܂�.
 */
class FunctionManager {
public:
	FunctionManager();
	~FunctionManager();
	/**
	 * �g�b�v���x���̊֐���ǉ����܂�.
	 * @param func
	 */
	void addFunction(Function* func);

	/**
	 * �w��̃V�O�l�`���̊֐���Ԃ��܂�.
	 * ������Ȃ�������nullptr��Ԃ��܂�.
	 * @param name
	 * @param argCount
	 */
	Function* const findFunction(std::string name, int argCount) const;

	/**
	 * �w��ʒu�̊֐���Ԃ��܂�.
	 * @param index
	 */
	Function* const getFunctionAt(int index) const;

	/**
	 * ���ɓ����V�O�l�`���̊֐�������Ȃ�true��Ԃ��܂�.
	 * @param func
	 * @return
	 */
	bool contains(Function* func) const;

	/**
	 * �S�Ă̊֐��̐���Ԃ��܂�.
	 * @return
	 */
	int getFunctionCount();
private:
	std::vector<Function*> funcVec;
};
#endif // !BEAN_ENV_FUNCTIONMANAGER_H

