#pragma once
#ifndef BEAN_ENV_USER_USERDELEGATE_H
#define BEAN_ENV_USER_USERDELEGATE_H
#include <memory>
#include "../Object_.h"
class ClassLoader;
class Delegate;
#include "../../threads/Thread.h"

using ClassLoaderSPtr = std::shared_ptr<ClassLoader>;
using ClassLoaderWPtr = std::weak_ptr<ClassLoader>;
/**
 * デリゲートのラッパー.
 */
class UserDelegate : public Object_ {
public:
	/**
	 * @param classLoader
	 * @param d
	 */
	UserDelegate(ClassLoaderSPtr, Delegate* d);
	~UserDelegate();
	/**
	 * このラムダが定義されたときのクラスローダーを返します.
	 * @return
	 */
	ClassLoaderSPtr getCapture() const;
	/**
	 * 実装を返します.
	 * @return
	 */
	Delegate* const getDelegate() const;

	/**
	 * Delegateへの委譲です.
	 * @param t
	 * @param args
	 */
	Object_* call(ThreadSPtr t, std::vector<Object_*> args);

	/**
	 * Delegateへの委譲です.
	 * @param args
	 */
	Object_* call(std::vector<Object_*> args);

	/**
	 * 動的メソッドのために作成されたラムダならtrue.
	 * @param b
	 */
	void setDynamicMethod(bool b);

	/**
	 * 動的メソッドのために作成されたラムダならtrue.
	 * @return b
	 */
	bool isDynamicMethod() const;

	// Object_ を介して継承されました
	virtual Object_ * clone() override;
	std::vector<Object_*> getVirtualField() override;
	UserDelegate* asUserDelegate() override;
protected:
	void lazyLoading() override;
private:
	ClassLoaderSPtr classLoader;
	Delegate* d;
	bool dynamicMethod;
};
#endif // !BEAN_ENV_USER_USERDELEGATE_H


