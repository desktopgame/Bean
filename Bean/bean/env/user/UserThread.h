#pragma once
#ifndef BEAN_ENV_USER_USERTHREAD_H
#define BEAN_ENV_USER_USERTHREAD_H
#include "../Object_.h"
#include "../../threads/Thread.h"
/**
 * スレッドのラッパー.
 */
class UserThread : public Object_ {
public:
	UserThread(std::string name);
	UserThread(ThreadSPtr t);
	~UserThread();

	/**
	 * 指定のデリゲートを実行するスレッドを開始します.
	 * @param ud
	 */
	void start(UserDelegate* ud);

	/**
	 * 既にスレッドが開始しているなら、
	 * 実行中のデリゲートを返します.
	 * @return
	 */
	UserDelegate* getDelegate() const;

	// Object_ を介して継承されました
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
