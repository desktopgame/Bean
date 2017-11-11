#pragma once
#ifndef BEAN_ENV_USER_USERTHREAD_H
#define BEAN_ENV_USER_USERTHREAD_H
#include "../Object_.h"
#include "../../threads/Thread.h"
/**
 * �X���b�h�̃��b�p�[.
 */
class UserThread : public Object_ {
public:
	UserThread(std::string name);
	UserThread(ThreadSPtr t);
	~UserThread();

	/**
	 * �w��̃f���Q�[�g�����s����X���b�h���J�n���܂�.
	 * @param ud
	 */
	void start(UserDelegate* ud);

	/**
	 * ���ɃX���b�h���J�n���Ă���Ȃ�A
	 * ���s���̃f���Q�[�g��Ԃ��܂�.
	 * @return
	 */
	UserDelegate* getDelegate() const;

	// Object_ ����Čp������܂���
	std::vector<Object_*> getVirtualField() override;
	virtual Object_ * clone() override;
	ThreadSPtr getThread();
	bool die() override;
	UserThread* asUserThread() override;
	static UserThread* const getCurrent();
protected:
	void lazyLoading() override;
private:
	ThreadWPtr thread;
	UserDelegate* ud;
};
#endif // !BEAN_ENV_USER_USERTHREAD_H
