#pragma once
#ifndef BEAN_ENV_USER_USERMUTEX_H
#define BEAN_ENV_USER_USERMUTEX_H
#include <mutex>
#include "../Object_.h"
/**
 * �~���[�e�b�N�X�̃��b�p�[.
 */
class UserMutex : public Object_ {
public:
	UserMutex();
	~UserMutex();
	/**
	 * ���b�N���l�����܂�.
	 */
	void lock();

	/**
	 * ���b�N���J�����܂�.
	 */
	void unlock();

	// Object_ ����Čp������܂���
	virtual Object_ * clone() override;
protected:
	std::recursive_mutex mutex;
	void lazyLoading() override;
};
#endif // !BEAN_ENV_USER_USERMUTEX_H
