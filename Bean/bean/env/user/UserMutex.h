#pragma once
#ifndef BEAN_ENV_USER_USERMUTEX_H
#define BEAN_ENV_USER_USERMUTEX_H
#include <mutex>
#include "../Object_.h"
/**
 * ミューテックスのラッパー.
 */
class UserMutex : public Object_ {
public:
	UserMutex();
	~UserMutex();
	/**
	 * ロックを獲得します.
	 */
	void lock();

	/**
	 * ロックを開放します.
	 */
	void unlock();

	// Object_ を介して継承されました
	virtual Object_ * clone() override;
protected:
	std::recursive_mutex mutex;
	void lazyLoading() override;
};
#endif // !BEAN_ENV_USER_USERMUTEX_H
