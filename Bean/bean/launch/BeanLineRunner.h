#pragma once
#ifndef BEAN_LAUNCH_BEANLINERUNNER_H
#define BEAN_LAUNCH_BEANLINERUNNER_H
#include <memory>
#include <vector>
#include "../env/ClassLoader.h"
#include "../ast/visitor/ASTInterpretVisitor.h"
class ASTInterpretVisitor;
/**
 * Bean�v���O��������s���Ƃɉ��߂���N���X.
 */
class BeanLineRunner {
public:
	/**
	 * ���݂̏�Ԃ�\�����ʎq.
	 */
	enum class State {
		Run,
		Err,
		Exit,
	};

	BeanLineRunner();
	~BeanLineRunner();

	/**
	 * �N���X���[�_�����������܂�.
	 */
	void initialize();

	/**
	 * �w��̈�s�����߂��܂�.
	 * @param line
	 */
	State eval(BString line);

	/**
	 * �W�����͂����s�ǂ݂���Ŏ��s���܂�.
	 */
	State eval();

	/**
	 * ���[�U�����^�[���R�[�h�����s����܂œ��͂����s���܂�.
	 */
	void evalWhile();

	/**
	 * ���̃I�u�W�F�N�g��j�����܂�.
	 */
	void exit();
private:
	std::vector<ASTNodeSPtr> nodeList;
	ClassLoaderSPtr placeHolder;
	ClassLoaderSPtr rootClsLoader;
	std::shared_ptr<ASTInterpretVisitor> visitor;
};
#endif // !BEAN_LAUNCH_BEANLINERUNNER_H
