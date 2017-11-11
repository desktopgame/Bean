#pragma once
#ifndef BEAN_ENV_USER_USERFILEPTR_H
#define BEAN_ENV_USER_USERFILEPTR_H
#include <stdio.h>
#include "../Object_.h"
/** 
 * �t�@�C���|�C���^�̃��b�p�[.
 */
class UserFilePtr : public Object_ {
public:
	UserFilePtr();
	~UserFilePtr();
	/**
	 * �w��̃��[�h�Ńt�@�C�����J���܂�.
	 * ���ɊJ����Ă���ꍇ�ɂ͗�O���X���[���܂��B
	 * @param mode
	 */
	void open(Numeric* mode);

	/**
	 * �ꕶ���ǂݍ��݂܂�.
	 * @return
	 */
	Numeric* read();

	/**
	 * �t�@�C�����N���[�Y���܂�.
	 * �܂��I�[�v������Ă��Ȃ��̂ɃN���[�Y���悤�Ƃ����ꍇ�͗�O���X���[���܂�.
	 */
	void close();

	// Object_ ����Čp������܂���
	virtual Object_ * clone() override;
private:
	FILE* ptr;

protected:
	void lazyLoading() override;
	int opened;
	int closed;
};
#endif // !BEAN_ENV_USERFILEPTR_H
