#pragma once
#ifndef BEAN_ENV_RUNTIME_H
#define BEAN_ENV_RUNTIME_H
#include <string>
#include <vector>
#include "../threads/Thread.h"
/**
 * Bean�̎��s��.
 */
class Runtime {
public:
	Runtime();
	~Runtime();

	/**
	 * ���ݎ��s���̃����^�C����Ԃ��܂�.
	 * @return
	 */
	static Runtime* const getCurrent();

	/**
	 * ���݂̃����^�C���ɕR�Â�����X���b�h��Ԃ��܂�.
	 * @param name
	 * @return
	 */
	static ThreadSPtr newThread(std::string name);

	/**
	 * �w��̃t�@�C�����N�����܂�.
	 * @param mainFile
	 */
	void exec(std::string mainFile);

	/**
	 * ���̃����^�C���Ɋ��蓖�Ă�ꂽID��Ԃ��܂�.
	 * @return
	 */
	int getID() const;
private:
	int id;
	static Runtime* current;
	static int index;
	void execImpl(std::string mainFile);
};
#endif // !BEAN_ENV_RUNTIME_H
